(define (list-sum ls)
  (apply + ls))

(define/contract (can-partition-grid grid)
  (-> (listof (listof exact-integer?)) boolean?)
  (let* ([sums-of-rows (map list-sum grid)]
         [sums-of-cols (apply map (cons + grid))]
         [sum-of-all (list-sum sums-of-rows)])
    (define (okay sums)
      (define (iter ls acc)
        (cond [(null? ls)
               false]
              [(= sum-of-all (* 2 acc))
               true]
              [else
               (iter (cdr ls) (+ acc (car ls)))]))
      (iter sums 0))
    (or (okay sums-of-rows) (okay sums-of-cols))))
