(define (get-min-distance nums target start)
  (let loop ([i 0]
             [ls nums]
             [best-dist 1010])
    (if (null? ls)
        best-dist
        (loop (add1 i)
              (rest ls)
              (if (= (first ls) target)
                  (min best-dist (abs (- i start)))
                  best-dist)))))
