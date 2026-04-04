(define (min-cost startPos homePos rowCosts colCosts)
  (define (sum ls)
    (apply + ls))
  (define (sublist-length ls start len)
    (take (drop ls start) len))
  (sum (map (lambda (costs i0 i1)
              (sum (sublist-length costs
                                   (min i1 (add1 i0))
                                   (abs (- i0 i1)))))
              (list rowCosts colCosts)
              startPos
              homePos)))
