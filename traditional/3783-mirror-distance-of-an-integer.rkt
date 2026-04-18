(define (num-reverse n)
  (let loop ([dest 0]
             [src n])
    (if (= 0 src)
        dest
        (let-values ([(quo rem) (quotient/remainder src 10)])
          (loop (+ rem (* 10 dest))
                quo)))))

(define/contract (mirror-distance n)
  (-> exact-integer? exact-integer?)
  (abs (- n (num-reverse n))))
