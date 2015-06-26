(defun insertR (new old lat)
	   (cond
	     ((null lat) (quote ()))
	     ((equal (car lat) old)
	      (cons (car lat) (cons new (cdr lat))))
	     (t (cons (car lat)
		      (insertR new old
			       (cdr lat))))))
(defun bytte (new old old2 lat)
	   (cond
	     ((null lat) (quote ()))
	     ((equal (car lat) old)
	      (cons new (cdr lat)))
	     ((equal (car lat) old2)
	      (cons new (cdr lat)))
	     (t (cons (car lat)
		      (bytte new old old2
			       (cdr lat))))))

(bytte 'math 'science 'i '(science is king))

(defun bytte2 (new o1 o2 lat)
  (cond
    ((null lat) (quote ()))
    ((or (eq (car lat) o1) (eq (car lat) o2))
     (cons new (cdr lat)))
    (t (cons (car lat)
	     (bytte2 new o1 o2 (cdr lat))))))

(bytte2 'rock 'pop 'gore '(h gore heie e h))

(bytte 'math 'science 'i '(mit i is king))

(defun multiinsertL (new old lat)
    (cond
      ((null lat) (quote ()))
      ((eq (car lat) old)
       (cons new
	     (cons old
		   (multiinsertL new old
		   (cdr lat)))))
      (t (cons (car lat) (multiinsertL new old
				     (cdr lat))))))

(multiinsertL 'rød 'dag '(i dag er en fin dag))

(defun addtup (tup)
  (cond
    ((null tup) 0)
    (t (+ (car tup) (addtup (cdr tup))))))

(addtup '(2 3))

(defun mult (n m)
  (cond
    ((zerop m) 0)
    (t (+ n (mult n (1- m))))))

(mult 2 3)

(defun tup+ (tup1 tup2)
  (cond
    ((null tup1) tup2)
    ((null tup2) tup1)
    (t (cons (+ (car tup1) (car tup2))
	      (tup+
	       (cdr tup1) (cdr tup2))))))

(tup+ '(1 3) '(6))

(defun greaterthan (n m)
  (cond
    ((zerop n) nil)
    ((zerop m) t)
    (t (greaterthan (1- n) (1- M)))))

(greaterthan -7 4)

(defun eksp (n m)
  (cond
    ((zerop m) 1)
    (t (mult n (eksp n (1- m))))))


(values 8 8 'h 'h "oehut")

(defun lengde (lat)
  (cond
    ((null lat) 0)
    (t (1+ lengde (cdr lat)))))

(length '(hei du der))2

(defun pick (n lat)
  (cond
    ((zerop (1- n)) (car lat))
    (t (pick (1- n) (cdr lat)))))

(pick 9 '(ja dette er en kort liten historie og niende ordet er))

(defun rempick (n lat)
  (cond
    ((zerop (1- n)) (cdr lat))
    (t (cons (car lat)
	     (rempick (1- n)
		      (cdr lat))))))

(rempick 4 '(nummer 4 du skal ut))
(rempick 2 '(kanskje ingen vi visste om ville rulle))

(defun no-nums (lat)
  (cond
    ((null lat) (quote ()))
    ((numberp (car lat))
     (no-nums (cdr lat)))
    (t (cons (car lat)
	     (no-nums
	      (cdr lat))))))

(no-nums '(2 be or nicht 2 be))

(defun all-nums (lat)
  (cond
    ((null lat) (quote ()))
    ((numberp (car lat))
     (cons (car lat)
	   (all-nums (cdr lat))))
    (t (all-nums (cdr lat)))))

(all-nums '(uhoetuhasoe  3 4 h))

(defun occur (a lat)
  (cond
    ((null lat) 0)
    ((equal (car lat) a)
	    (1+ (occur a (cdr lat))))
    (t (occur a (cdr lat)))))

(occur 3 '(3 3 uehou 3))

(defun onep (n)
  (equal n 1))
(onep 1)

(defun rempick (n lat)
  (cond
    ((null lat) (quote ()))
    ((onep n) (cdr lat))
    (t (cons (car lat)
	     (rempick (1- n) (cdr lat))))))

(rempick 4 '(uh å vi e no bra heldig))

(defun rember* (a l)
  (cond ((null l) (quote ()))
	((atom (car l))
	 (cond ((equal (car l) a) (rember* a (cdr l)))
	       (t (cons (car l)
			(rember* a (cdr l))))))
	(t (cons (rember* a (car l))
		 (rember* a (cdr l))))))


(rember* 'coffe '((tea) and coffe (but not (tea) and coffe)))
(rember* 3 '(((3)) 3 4 3))

(defun occur* (a l)
  (cond ((null l) 0)
	((atom (car l))
	 (cond
	   ((equal (car l) a)
	    (1+ (occur* a (cdr l))))
	   (t (occur* a (cdr l)))))
	(t (+ (occur* a (car l))
	      (occur* a (cdr l))))))

(occur* 5 '(5 34 5 uheotuo "oeuh" ueoh 55 5 5 5))

(defun bytte* (new old l)
  (cond ((null l) (quote()))
	((atom (car l))
	 (cond ((equal old (car l))
		(cons new
		      (bytte* new old (cdr l))))
	       (t (cons (car l)
			(bytte* new old (cdr l))))))
	(t (cons (bytte* new old (car l))
		 (bytte* new old (cdr l))))))

(bytte* 'hei 'hade '( han sa (hade)))

(defun insertL* (new old l)
  (cond
    ((null l) (quote ()))
    ((atom (car l))
     (cond
       ((equal (car l) old)
	(cons new
	      (cons old
		    (insertL* new old
			      (cdr l)))))
       (t (cons (car l)
		(insertL* new old
			  (cdr l))))))
    (t (cons (insertL* new old
		       (car l))
	     (insertL* new old
		       (cdr l))))))

(insertL* 'god 'middag '(ete middag))

(defun leftmost (l)
  (cond
    ((null (car l)) (quote ()))
    ((atom (car l)) (car l))
    (t (leftmost (car l)))))

(leftmost '(((hei) (he9)) i))

(defun eqlist (l1 l2)
  (cond
    ((and (null l1) (null l2)) t)
    ((or (null l1) (null l2)) nil)
    ((and (atom (car l1))
	  (atom (car l2)))
     (and (equal (car l1) (car l2))
	  (eqlist (cdr l1) (cdr l2))))
    ((atom (car l1)) nil)
    ((null l2) nil)
    (t
     (and (eqlist (car l1) (car l2))
	  (eqlist (cdr l1) (cdr l2))))))

(eqlist '(2 heia) '( 2 heia))
	       
(defun equal? (s1 s2)
  (cond
    ((and (atom s1) (atom s2))
     (equal s1 s2))
    ((or (atom s1) (atom s2)) nil)
    (t (eqlist s1 s2))))

(equal? 'hei 'hei)
(equal? 2 'to)

(defun eqlist (l1 l2)
  (cond
    ((and (null l1) (null l2) t))
    ((or (null l1) (null l2) nil))
    ((and (equal? (car l1) (car l2))
	  (eqlist (cdr l1) (cdr l2))))))
(eqlist '(ni og to) '(ni og to))
(eqlist '(ni og t2) '(9 og 2))

(defun rember (s l)
  (cond
    ((null l) (quote ()))
    ((equal (car l) s) (cdr l))
    (t (cons (car l)
       (rember s (cdr l))))))

(rember '(a(x)) '((a(x)) b c a))

(defun value (nexp)
  (cond
    ((atom nexp) nexp)
    ((eq (car (cdr nexp)) (quote +))
     (+ (value (car nexp))
	(value (car (cdr (cdr nexp))))))
    ((eq (car (cdr nexp)) (quote *))
     (* (value (car nexp))
	(value (car (cdr (cdr nexp))))))))

(value (car (cdr (cdr '(2 + 2)))))

(value '(2 + 2))

(defun set? (lat)
  (cond
    ((null lat) t)
    ((member (car lat) (cdr lat)) nil)
    (t (set? (cdr lat)))))

(set? '(a 3 4 2 2))

(defun makeset (lat)
  (cond
    ((null lat) (quote ()))
    ((member (car lat) (cdr lat))
     (makeset (cdr lat)))
    (t (cons (car lat)
	     (makeset (cdr lat))))))

(makeset '(2 3 2))

(defun subset (set1 set2)
  (cond
    ((null set1) t)
    ((member (car set1) set2)
     (subset (cdr set1) set2))
    (t nil)))
(subset '(jokeke og andre) '(vi hører på jokeke og andre))

(defun subset (set1 set2)
  (cond
    ((null set1) t)
    ((and (member (car set1) set2)
	  (subset (cdr set1) set2))
     t)))

(subset '(nei det var da) '(det var da som svarte nei))

(defun eqset (set1 set2)
  (and (subset set1 set2)
       (subset set2 set1)))

(eqset '(hei på deg) '(hei deg på ja))

(defun intersect (set1 set2)
  (cond
    ((null set1) nil)
    ((member (car set1) set2)
     (cons (car set1)
	   (intersect (cdr set1) set2)))
    (t
     (intersect (cdr set1) set2))))

(intersect '(ja da) '(hei da))
(intersect '() '(på låven))
(member 'ha '(ja ha på))

(defun union** (set1 set2)
  (cond
    ((null set1) set2)
    ((null set2) set1)
    ((member (car set1) set2)
     (union* (cdr set1) set2))
    (t (cons
	(car set1)
	(union** (cdr set1) set2)))))


(defun intersectall (l-set)
  (cond
    ((null (cdr l-set)) (car l-set))
    (t
     (intersect (car l-set)
		(intersectall (cdr l-set))))))
  
(intersectall '((k x) (k x) (h k  x) (h x k uheotu oheu)))

(defun a-pair (l)
  (cond
    ((or (atom l)
         (null l)
	 (null (cdr l))
	 (null (cadr l)))
     nil)
    (t t)))
(a-pair '((list) this))
(a-pair '(list this yes))

(defun build (s1 s2)
  (cons s1 (cons s2 ())))
(build 2 3)

(third '(e e eu))

(defun set? (lat)
  (cond
    ((null lat) t)
    ((member (car lat) (cdr lat))
     nil)
    (t
     (set? (cdr lat)))))
(defun firsts (lat)
  (cond
    ((null lat) (quote ()))
    (t
     (cons (caar lat)
	   (firsts (cdr lat))))))
(defun seconds (lat)
  (cond
    ((null lat) (quote ()))
    (t
     (cons (cadar lat)
	   (seconds (cdr lat))))))
(seconds '((3 3) (35 55)))
(defun fun? (rel)
  (set? (firsts rel)))

(defun revrel (rel)
  (cond
    ((null rel) (quote ()))
    (t
     (cons (build
	    (second (car rel))
	    (first (car rel)))
	   (revrel (cdr rel))))))

(revrel '((a b) (1 2) (først sist)))

(defun fullfun (fun)
  (set? (seconds (fun))))

(defun eq?-c (a)
  (function
   (lambda (x)
    (eq x a))))

(defun eq?-salad (a) (print a))
(setq eq?-salad (eq?-c 'salad))

(funcall eq?-salad 2)
(funcall eq?-salad 'salad)
(funcall (eq?-c 'salad) 'salad)

(defun rember-f (test?)
  #'(lambda (a l)
    (cond
      ((null l) (quote ()))
      ((funcall test? a (car l)) (cdr l))
      (t (cons (car l)
	       (funcall (rember-f test?) a (cdr l)))))))

(funcall (rember-f #'equal) 4 '(3 4 4))

(defun multiremberT (test? lat)
  (cond
    ((null (car lat)) (quote ()))
    ((funcall test? (car lat))
     (multiremberT test? (cdr lat)))
    (t (cons (car lat) (multiremberT test? (cdr lat))))))

(multiremberT eq?-salad '(salad h salad heia huo egg))
(multiremberT (eq?-c 'bok) '(kan bok lese bok))

(defun multirember&co (a lat col)
  (cond ((null lat) (funcall col '() '()))
	((eq (car lat) a)
	 (multirember&co a
			 (cdr lat)
			 (lambda (newlat seen)
			   (funcall col newlat
				(cons (car lat) seen)))))
	(t (multirember&co a
			   (cdr lat)
			   (lambda (newlat seen)
			     (funcall col (cons (car lat) newlat)
				  seen))))))
(defun llengde (x y)
  (length x))
(multirember&co 'tuna '(strawberries tuna and swordfish) 'llengde)

(defun multiinsertLR (new oldL oldR lat)
  (cond ((null lat) '())
	((eq oldL (car lat))
	 (cons new
	       (cons oldL (multiinsertLR
		    new oldL oldR (cdr lat)))))
	((eq oldR (car lat))
	 (cons oldR
	       (cons new
		     (multiinsertLR
		      new oldL oldR (cdr lat)))))
	(t (cons (car lat)
		 (multiinsertLR
		  new oldL oldR (cdr lat))))))

(multiinsertLR 'inne 'og 'kanskje '(hun skulle kanskje gå ute og borte))

(defun evens-only* (l)
  (cond ((null l) '())
	((atom (car l))
	 (cond
	   ((evenp (car l))
	    (cons (car l)
		  (evens-only* (cdr l))))
	   (t (evens-only* (cdr l)))))
	(t (cons (evens-only* (car l))
		 (evens-only* (cdr l))))))
	
(evens-only* '(2 3 4 (5 35  5  22 6 4) 3))

(defun keep-looking (a sorn lat)
  (cond ((numberp sorn)
	 (keep-looking a (pick sorn lat) lat))
	(t (eq sorn a))))
(pick 3 '(h te a))

(defun looking (a lat)
  (keep-looking a (pick 1 lat) lat))

(looking 'caviar '(2 3 4 caviar))

(defun shift (pair)
  (cond ((null pair) '())
	(t (build (first (first pair))
		  (build (second (first pair))
			 (second pair))))))

(shift '((a d) (u ht)))
(build 3 34)

(defun C (n)
  (cond ((eq 1 n) 1)
	((evenp n) (C (/ n 2)))
	(t (C (1+ (* 3 n))))))

;; (defun A (n m)
;;   (cond
;;     ((zerop n) (1+ m)) 
;;     ((zerop m) (A (1- n) 1))
;;     (t (A (1- n) (A n (1- m))))))

;; (A 4 3)

(defun lookup-in-entry (name entry entry-f)
  (lookup-in-entry-help name
			(first entry)
			(second entry)
			entry-f))

(defun lookup-in-entry-help (name names values entry-f)
  (cond ((null names) (funcall entry-f name))
	((eq (car names) name)
	 (car values))
	(t (lookup-in-entry-help name
				 (cdr names)
				 (cdr values)
				 entry-f))))
(lookup-in-entry 'heid '((qa hei) (ja nei)) 'print)

(defun lookup-in-table (name table table-f)
  (cond ((null table) (funcall table-f name))
	(t (lookup-in-entry name
			     (car table)
			     (lambda (name)
			       (lookup-in-table name
						(cdr table)
						table-f))))))

(lookup-in-table 'middag '(((1 2 middag) (jo nei halden)) ((2 3 dessert) (hi ho sno))) 'print)

(defun insertL-f (test?)
  #'(lambda (new old l)
      (cond ((null l) '())
	    ((funcall test? (car l) old)
	     (cons new (cons old (cdr l))))
	    (t (cons (car l)
		     (funcall (insertR-f test?) new old
			      (cdr l)))))))
(funcall (insertL-f 'eq) 'ny 'gamal '(gamal ost))

(defun insertR-f (test?)
  #'(lambda (new old l)
      (cond ((null l) '())
	    ((funcall test? (car l) old)
	     (cons old (cons new (cdr l))))
	    (t (cons (car l)
		     (funcall (insertR-f test?) new old
		      (cdr l)))))))
(funcall (insertR-f #'eq) 'ny 'gamal '(gamal ost))

(defun seqL (new old l)
  (cons new (cons old l)))
(defun seqR (new old l)
  (cons old (cons new l)))

(defun insert-g (seq)
  #'(lambda (new old l)
      (cond ((null l) '())
	    ((funcall #'eq (car l) old)
	     (funcall seq new old (cdr l)))
	    (t (cons (car l)
		     (funcall (insertR-f test?) new old
			      (cdr l)))))))
(funcall (insert-g 'seqL) 'new 'old '(old boy))

(defvar insertL (insert-g 'seqL))
(defun insertL (new old l)
  (funcall (insert-g 'seqL) new old l))
(funcall insertL 'new 'old '(old man))
(insertL 'new 'old '(old car))

(defun atom-to-function (x)
  (cond
    ((eq x '+)
     (lambda (m n) (+ m n)))
    ((eq x '*)
     (lambda (m n) (* m n)))))

(funcall (atom-to-function '+) 2 3)
(funcall (lambda (m n) (+ m n)) 2 3)
(funcall (atom-to-function '+) 2 2)

(defun align (pora)
  (cond
   ((atom pora) pora)
   ((a-pair (first pora))
    (align (shift pora)))
   (t (build (first pora)
	     (align (second pora))))))

(align '((2 3) (a b)))
(align '(2 (3 4 5 6)))

(defun length* (pora)
  (cond
    ((atom pora) 1)
    (t (+ (length* (first pora))
	  (length* (second pora))))))

(length* '(2 (3 (3 4)) 5))
(align '((2 (13 14)) (b a)))

(defun weigth* (pora)
  (cond
    ((atom pora) 1)
    (t (+ (* (weigth* (first pora)) 2)
	  (weigth* (second pora))))))
(weigth* '((a b) c))
(weigth* '(a (b c)))

(defun revpair (pair)
  (build (second pair) (first pair)))

(defun shuffle (pora)
  (cond
    ((atom pora) pora)
    ((a-pair (first pora)) (shuffle (revpair pora)))
    (t (build (first pora)
	      (shuffle (second pora))))))

(shuffle '(a (b c)))

(defun lengde (l)
  (cond
    ((null l) 0)
    (t (1+ (length (cdr l))))))
(lengde '(3 4 uoeu (euo eou)))

(defun eternity (x)
  (eternity x))

(eternity 4)

((lambda (l)
   (cond
     ((null l) 0)
     (t (1+ (eternity (cdr l))))))
 '())


((lambda (l)
  (cond
    ((null l) 0)
    (t(1+((lambda (l)
	    (cond
	      ((null l) 0)
	      (t (1+ (eternity
		      (cdr l))))))
	  (cdr l)))))) '(3))

(funcall ((lambda (length)
   (lambda (l)
     (cond
       ((null l) 0)
       (t (1+ (funcall length (cdr l)))))))
	  'eternity) '())


(funcall ((lambda (f)
	    (lambda (l)
	      (cond
       ((null l) 0)
       (t (1+ (funcall f (cdr l)))))))
	  ((lambda (g)
	     (lambda (l)
	       (cond
		 ((null l) 0)
		 (t (1+ (funcall g (cdr l)))))))
	   'eternity))
	 '(21))

;; Recursion using mk-length
(funcall ((lambda (mk-length)
	    (funcall mk-length 'eternity))
	  (lambda (length)
	    (lambda (l)
	      (cond
		((null l) 0)
		(t (1+ (funcall length (cdr l))))))))
	 '(2))

(funcall ((lambda (mk-length)
	    (funcall mk-length
		     (funcall mk-length
			      (funcall mk-length
				       (funcall mk-length
						'eternity)))))
	  (lambda (length)
	    (lambda (l)
	      (cond
		((null l) 0)
		(t (1+ (funcall length (cdr l))))))))
	 '(2 4 3 4))

(funcall ((lambda (mk-length)
	    (funcall mk-length mk-length))
	  (lambda (mk-length)
	    (lambda (l)
	      (cond
		((null l) 0)
		(t (1+ (funcall
			(funcall mk-length
				 mk-length) (cdr l))))))))
	 '(9 8 7 6 5))



(funcall ((lambda (mk-length)
	    (funcall mk-length mk-length))
	  (lambda (mk-length)
	    (lambda (l)
	      (cond
		((null l) 0)
		(t (1+ ((lambda (x)
			  (funcall
			   (funcall mk-length
				    mk-length) x))
			(cdr l))))))))
	 '(1 2 3))
(funcall ((lambda (mk-length)
	    (funcall mk-length mk-length))
	  (lambda (mk-length)
	    ((lambda (length)
	       (lambda (l)
		 (cond
		   ((null l) 0)
		   (t (1+ (funcall length (cdr l)))))))
	     (lambda (x)
			  (funcall
			   (funcall mk-length
				    mk-length) x)))))
	    '(1 2 3 4 89 hths bsth funker for alt))

(funcall ((lambda (le)
	    ((lambda (mk-length)
	       (funcall mk-length mk-length))
	     (lambda (mk-length)
	       (funcall le (lambda (x)
			  (funcall
			   (funcall mk-length
				    mk-length) x))))))
	  (lambda (length)
	    (lambda (l)
	      (cond
		((null l) 0)
		(t (1+ (funcall length (cdr l))))))))
	 '(2 3))

(defun Y (le)
  ((lambda (f)
     (funcall f f))
     (lambda (f)
       (funcall le (lambda (x) (funcall
				(funcall f f) x))))))
(defvar lengde (lambda (length)
	    (lambda (l)
	      (cond
		((null l) 0)
		(t (1+ (funcall 'length (cdr l))))))))
(funcall (Y
	  (lambda (length)
	    (lambda (l)
	      (cond
		((null l) 0)
		(t (1+ (funcall 'length (cdr l)))))))
	 '(2 4 5))

(funcall (y lengde) '(4 5))
(funcall #'length '())

(funcall (funcall  (lambda (mk-length)
		     ((lambda (length)
			(lambda (l)
			  (cond
			    ((null l) 0)
			    (t (1+ (funcall length (cdr l)))))))
		      (lambda (x)
			(funcall
			 (funcall mk-length
				  mk-length) x))))
		   (lambda (mk-length)
		     ((lambda (length)
			(lambda (l)
			  (cond
			    ((null l) 0)
			    (t (1+ (funcall length (cdr l)))))))
		      (lambda (x)
			(funcall
			 (funcall mk-length
				  mk-length) x)))))

	 '(1 2 3 4 89 hths bsth funker for alt))
(funcall (funcall (lambda ( mk-length)
		    (funcall mk-length mk-length))
		  (lambda (mk-length)
		    (lambda (l)
		      (cond
			((null l) 0)
			(t (1+
			    (funcall mk-length ( cdr l))))))))
	 '())

(funcall #'print 2)
