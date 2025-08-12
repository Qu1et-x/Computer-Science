(define (over-or-under num1 num2) (cond 
  ((< num1 num2) -1)
  ((= num1 num2) 0)
  ((> num1 num2) 1)))

(define (max a b)
  (if (> a b)
      a
      b))

(define (min a b)
  (if (> a b)
      b
      a))

(define (gcd a b) (let (
  (x (min a b))
  (y (max a b)))
  (if (zero? (modulo y x)) x (gcd x (modulo y x)))))

(define (remove item lst) (filter (lambda (x) (not (= x item))) lst))

(define (duplicate lst) (if (null? lst) lst (cons (car lst) (cons (car lst) (duplicate (cdr lst))))))

(expect (duplicate '(1 2 3)) (1 1 2 2 3 3))

(expect (duplicate '(1 1)) (1 1 1 1))

(define (composed f g) (lambda (x) (f (g x))))

(define (repeat f n) (if (zero? n) (lambda (x) x) (composed f (repeat f (- n 1)))))
