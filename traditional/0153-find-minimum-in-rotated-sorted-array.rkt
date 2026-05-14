(define/contract (find-min nums)
  (-> (listof exact-integer?) exact-integer?)
  (let ([v (list->vector nums)]
        [head (first nums)])
    (define (bisect l r)
      (if (>= l r)
          l
          (let ([mid (quotient (+ l r) 2)])
            (if (>= (vector-ref v mid) head)
                (bisect (add1 mid) r)
                (bisect l mid)))))
    (vector-ref v
                (let ([n (vector-length v)])
                  (remainder (bisect 0 n) n)))))
