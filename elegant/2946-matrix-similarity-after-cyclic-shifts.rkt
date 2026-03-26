(define/contract (are-similar mat k)
  (-> (listof (listof exact-integer?)) exact-integer? boolean?)
  (let* ([n (length (car mat))]
         [l (remainder k n)])
    (andmap (lambda (row)
              (let-values ([(left right) (split-at row l)])
                (andmap identity (map = row (append right left)))))
             mat)))
