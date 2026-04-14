(define (closest-target words target startIndex)
  (let ([len (length words)])
    (let ([res (let loop ([i 0]
                          [ls words]
                          [best len])
                 (if (null? ls)
                     best
                     (loop (add1 i)
                           (rest ls)
                           (if (string=? (first ls) target)
                               (min best
                                    (let ([dist (abs (- i startIndex))])
                                      (min dist (- len dist))))
                               best))))])
      (if (= res len)
          -1
          res))))
