
(define a 1)

(define b 2)

(define f (lambda (m n) (+ m n)))

(define l (quote ((a b) c d)))

(define fact (lambda (n) (if (= n 0) 1 (* n (fact (- n 1))))))

(define fib (lambda (n) (if (= n 0) 1 (if (= n 1) 1 (+ (fib (- n 1)) (fib (- n 2)))))))

(fact 10)

(fib 10)

(definestat f (lambda (n) (+ a n)))

(define a 5)

(stats #t)

(f a)
