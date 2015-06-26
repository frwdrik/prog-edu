(load "~/Documents/Programming/thelittleschemer.lisp")

(defun atom-to-action (a)
  (cond
    ((or (numberp a)
	 (eq a t)
	 (eq a nil)
	 (eq a 'cons)
	 (eq a 'car)
	 (eq a 'null)
	 (eq a 'eq)
	 (eq a 'atom)
	 (eq a 'zero)
	 (eq a '1+)
	 (eq a '1-)
	 (eq a 'numberp))
     '*const)
    (t '*identifier)))h

(defun list-to-action (e)
  (cond
    ((atom (car e))
     (cond
       ((eq (car e) 'quote) '*quote)
       ((eq (car e) 'lambda) '*lambda)
       ((eq (car e) 'cond) '*cond)
       (t '*application)))
    (t '*application)))

(defun expression-to-action (e)
  (cond
    ((atom e) (atom-to-action e))
    (t (list-to-action e))))

(defun value (e)
  (meaning e '()))
(defun meaning (e table)
  (funcall (expression-to-action e) e table))

;; Action if e is a constant
(defun *const (e table)
  (cond
    ((numberp e) e)
    ((eq e t) t)
    ((eq e nil) nil)
    (t (build 'primitive e))))

;;; These are our actions if e is a list
(defun *application (e table)
  (apply*
   (meaning (function-of e) table)
   (evlis (arguments-of e) table)))
;; *application help functions
(defun function-of (x)
  (car x))
(defun arguments-of (x)
  (cdr x))

(defun *quote (e table)
  (text-of e))
;; *quote help functions
(defun text-of (e)
  (second e))

(defun *identifier (e table)
  (lookup-in-table e table 'initial-table))

(defun *lambda (e table)
  (build 'non-primitive
	 (cons table (cdr e))))

(defun evcon (lines table)
  (cond
    ((else? (question-of (car lines)))
     (meaning (answer-of (car lines))
	      table))
    ((meaning (question-of (car lines))
	      table)
     (meaning (answer-of (car lines))
	      table))
    (t (evcon (cdr lines) table))))

;; evcon help functions
(defun else? (x)
  (cond
    ((atom x) (eq x 't))
    (t nil)))
(defun question-of (x)
  (first x))
(defun answer-of (x)
  (second x))
(defun cond-lines-of (x)
  (cdr x))

(defun *cond (e table)
  (evcon (cond-lines-of e) table))

(defun initial-table (name)
  (car '()))

;;; Functions for evaluation of applications

(defun evlis (args table)
  (cond
    ((null args) '())
    (t
     (cons (meaning (car args) table)
	   (evlis (cdr args) table)))))

(defun primitive? (l)
  (eq (first l) 'primitive))
(defun non-primitiv? (l)
  (eq (first l) 'non-primitive))


(defun apply* (fun vals)
  (cond
    ((primitive? fun)
     (apply-primitive
      (second fun) vals))
    ((non-primitive? fun)
     (apply-closure
      (second fun) vals))))

(defun apply-primitive (name vals)
  (cond
    ((eq name 'cons)
     (cons (first vals) (second vals)))
    ((eq name 'car)
     (car (first vals)))
    ((eq name 'cdr)
     (cdr (first vals)))
    ((eq name 'null)
     (null (first vals)))
    ((eq name 'atom)
     (atom (first vals)))
    ((eq name 'zerop)
     (zerop (first vals)))
    ((eq name '1+)
     (1+ (first vals)))
    ((eq name '1-)
     (1- (first vals)))
    ((eq name 'numberp)
     (numberp (first vals)))))

(defun apply-closure (closure vals)
  (meaning (body-of closure)
	   (extend-table
	    (new-entry
	     (formals-of closure)
	     vals)
	    (table-of closure))))
(defun extend-table (entry table)
  (cons entry table))
