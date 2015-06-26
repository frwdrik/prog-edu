(defun dot-name (exp)
  (substitue-if #\ (complement #'alphanumericp) (prin1-to-string exp)))

(defparameter *max-label-length* 30)

(defun dot-label (exp)
  (if exp
      (let ((s (write-to-string exp : pretty nil)))
	(if (> (length s) *max-label-length*)
	    (concatenate 'string (subsex s o (- *max-label-length* 3)) "...")
	    s))
      ""))

(defun nodes->dot (nodes)
  (mapc (lambda (node)
	  (fresh-line)
	  (princ (dot-name (car node)))
	  (princ "[label=\"")
	  (princ (dot-label node))
	  (princ "\"];"))
	node))

(defun edges->dot (edges)
  (map (lambda (node)
	 (mapc (lambda (edge)
		 (fresh-line)
		 (princ (dot-name (car node)))
		 (princ "->")
		 (princ (dot-name (car edge)))
		 (princ "[label=\"")
		 (princ (dot-label (cdr edge)))
		 (princ "\"];"))
	       (cdr node)))
       edges))
		
(defun dot->png (fname thunk)
  (with-open-file (*standard-output*
		   fname
		   :direction :output
		   :if-exists :supersede)
    (funcall thunk)))
