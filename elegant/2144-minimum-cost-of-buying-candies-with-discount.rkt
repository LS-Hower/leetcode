(define #|/contract|# (minimum-cost cost)
  #|(-> (listof exact-integer?) exact-integer?)|#
  (let iter ([ls (sort cost >)]
             [acc 0])
    (match ls
      [(list* a b c tail)
       (iter tail (+ acc a b))]
      [else
       (apply + acc ls)])))
