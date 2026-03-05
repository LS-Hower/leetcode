(define (concatenated-binary n)
    (define (iter i acc)
        (if (> i n)
            acc
            (iter (+ i 1)
                  (remainder (bitwise-ior (arithmetic-shift acc
                                                            (integer-length i)) i)
                             1000000007))))
    (iter 1 0))
