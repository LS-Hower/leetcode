(define/contract (min-element nums)
  (-> (listof exact-integer?) exact-integer?)
  (letrec ([digsum (lambda (num)
                     (if (zero? num)
                         0
                         (let-values ([(quo rem) (quotient/remainder num 10)])
                           (+ rem (digsum quo)))))])
    (apply min (map digsum nums))))
