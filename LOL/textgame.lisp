;;; lisp --- A simple text-based game engine

;;; Code:

;; Define our locations

(defparameter *nodes* '((living-room (you are in the living-room.
				a wizard is snoring loudly on the couch.))
                        (garden (you are in a beautiful garden.
				there is a well in front of you.))
			(attic (you are in the attic.
				    there is a giant welding torch in the corner.))))
;; using assoc to extract info about location
(defun describe-location (location nodes)
  (cadr (assoc  location nodes)))

(describe-location 'living-room *nodes*)

;;define our paths
(defparameter *edges* '((living-room (garden west door)
				     (attic upstairs ladder))
			(garden (living-room east door))
			(attic (living-room downstairs ladder))))

;; using c*r to extract info about paths
(defun describe-path (edge)
  `(there is a ,(caddr edge) going ,(cadr edge) from here.))
(describe-path '(garden west door))

;; describe all paths leading from a location
(defun describe-paths (location edges)
  (apply #'append (mapcar #'describe-path (cdr (assoc location edges)))))
(describe-paths 'living-room *edges*)

;; create a list of objects and a list of their location
(defparameter *objects* '(whiskey bucket frog chain))
(defparameter *object-locations* '((whiskey living-room)
				   (bucket living-room)
				   (frog garden)
				   (chain attic)))

;; lists objects visible from a given location. lablels is used to declare local function.
(defun objects-at (loc objs obj-locs)
  (labels ((at-loc-p (obj)
	     (eq (cadr (assoc obj obj-locs)) loc)))
    (remove-if-not #'at-loc-p objs)))

;; describe objects visible at a given location
(defun describe-objects (loc objs obj-loc)
  (labels ((describe-obj (obj)
	     `(you see a ,obj on the floor.)))
    (apply #'append (mapcar #'describe-obj (objects-at loc objs obj-loc)))))

;; initialize location
(defparameter *location* 'living-room)

;; looking around the room
(defun look ()
  (append (describe-location *location* *nodes*)
	  (describe-paths *location* *edges*)
	  (describe-objects *location* *objects* *object-locations*)))
;; walk function: takes a direction and let us walk there
(defun walk (direction)
  (let ((next (find direction
		    (cdr (assoc *location* *edges*))
		    :key #'cadr)))
    (if next
	(progn (setf *location* (car next))
	       (look))
	'(you cannot go that way.))))
;; picking up objects
(defun pickup (object)
  (cond ((member object
		 (objects-at *location* *objects* *object-locations*))
	 (push (list object 'body) *object-locations*)
	 `(you are now carrying the ,object))
	(t '(you cannot get that.))))

;; checking our inventory ()
(defun inventory ()
  (cons '-items (objects-at 'body *objects* *object-locations*)))
;; custom text interface

;; customizing our REPL

(defun game-read ()
  (let ((read-cmd (read-from-string
		   (concatenate 'string "(" (read-line) ")"))))
    (flet ((quote-it (x)
	     (list 'quote x)))
      (cons (car read-cmd) (mapcar #'quote-it (cdr read-cmd))))))

(defparameter *allowed-commands* '(look walk pickup inventory))
(defun game-eval (sexp)
  (if (member (car sexp) *allowed-commands*)
      (eval sexp)
      '(i do not know that command.)))

(defun tweak-text (lst caps lit)
  (when lst
    (let ((item (car lst))
	  (rest (cdr lst)))
      (cond ((eq item #\space) (cons item (tweak-text rest caps lit)))
	    ((member item '(#\! #\? #\.)) (cons item (tweak-text rest t lit)))
	    ((eq item #\") (twek-text rest caps (not lit)))
	    (lit (cons item (tweak-text rest nil lit)))
	    ((or caps lit) (cons (char-upcase item) (tweak-text rest nil lit)))
	    (t (cons (char-downcase item) (tweak-text rest nil nil)))))))
(defun string-trim-to-list (chars string)
  (let ((lst (coerce string 'list))
	(clst (coerce chars 'list)))
    (let ((end-pos (1- (length lst))))
      (when lst
	(if (member (nth  end-pos lst) clst)
	    (setf lst (butlast lst 1)))
	(if (member (car lst) clst)
	    (cdr lst)
	    (list 'quote lst))))))
(defun game-print (lst)
  (princ (coerce (tweak-text (string-trim-to-list "() "
						  (prin1-to-string lst))
			     t
			     nil)
		 'string))
  (fresh-line))

(defun game-repl ()
  (let ((cmd (game-read)))
    (unless (eq (car cmd) 'quit)
      (game-print (game-eval cmd))
      (game-repl))))

(defun have (object)
  (member object (inventory)))

;; macro for defining new game actions
(defmacro game-action (command subj obj place &body body)
  `(progn (defun ,command (subject object)
	    (if (and (eq *location* ',place)
		     (eq subject ',subj)
		     (eq object ',obj)
		     (have ',subj))
		,@body
		'(i cant ,command like that.)))
	  (pushnew ',command *allowed-commands*)))

(defparameter *chain-welded* nil)
(game-action weld chain bucket attic
  (if (and (have'bucket) (not *chain-welded*))
      (progn (setf *chain-welded* 't)
	     '(the chain is now securely welded to the bucket.))
      '(you do not have a bucket.)))

(defparameter *bucket-filled* nil)
(game-action dunk bucket well garden
  (if *chain-welded*
      (progn (setf *bucket-filled* 't)
	     '(the bucket is now full of water))
      '(the water level is too low to reach.)))
	        
(game-action splash bucket wizard living-room
  (cond ((not *bucket-filled*) '(the bucket has nothing in it))
	((have 'frog) '(the wizard awakens and sees that you stole his frog. he is so upset he banishes you to the netherwordl - you lose! the end.))
	(t '(the wizard awakens from his slumber and greets you warmly. he hands you the magic low-carb donut - you win! the end.))))
