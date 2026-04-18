(define (num-reverse n)
  (let loop ([dest 0]
             [src n])
    (if (= 0 src)
        dest
        (let-values ([(quo rem) (quotient/remainder src 10)])
          (loop (+ rem (* 10 dest))
                quo)))))

(define (min-mirror-pair-distance-internal nums)
  (let loop ([i 0]
             [ls nums]
             [tbl (make-immutable-hash)]
             [best 100010])
    (if (null? ls)
        best
        (let ([head (first ls)]
              [tail (rest ls)])
          (loop (add1 i)
                tail
                (hash-set tbl (num-reverse head) i)
                (if (hash-has-key? tbl head)
                    (min best
                         (- i (hash-ref tbl head)))
                    best))))))

(define (min-mirror-pair-distance nums)
  (let ([res (min-mirror-pair-distance-internal nums)])
    (if (= 100010 res)
        -1
        res)))
