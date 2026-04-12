(define (get-min-distance nums target start)
  (let loop ([ls nums]
             [i 0]
             [best-dist 1010])
    (if (null? ls)
        best-dist
        (loop (rest ls)
              (add1 i)
              (let ([i-dist (abs (- i start))])
                (if (and (= (first ls) target)
                         (< i-dist best-dist))
                    i-dist
                    best-dist))))))
