(define (exp b n)
  (define (helper n so-far) (if (= n 0) so-far (helper (- n 1) (* so-far b))))
  (helper n 1))

(define (last s) (if (null? (cdr s)) (car s) (last (cdr s))))

(define (swap s) 
  (define (swap-helper s ls)
    (cond 
      ((null? s) ls)
      ((null? (cdr s)) (append ls (cons (car s) (list))))
      (else (swap-helper (cdr (cdr s)) (append ls (cons (car (cdr s)) (cons (car s) (list))))))))
  (swap-helper s ()))

(define (concatenate s) 
  (define (con-helper s ls)
    (if (null? s) 
      ls
      (con-helper (cdr s) (append ls (car s)))))
  (con-helper s ()))

(define (filter pred lst) 
  (define (filter-helper lst s)
    (cond
      ((null? lst) s)
      ((pred (car lst)) (filter-helper (cdr lst) (append s (list (car lst)))))
      (else (filter-helper (cdr lst) s))))
  (filter-helper lst ()))
