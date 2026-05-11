(define/contract (minimum-effort tasks)
  (-> (listof (listof exact-integer?)) exact-integer?)
  (foldl (lambda (t m)
           (max (+ m (first t))
                (second t)))
         0
         (sort tasks
               <
               #:key (lambda (t)
                       (- (second t)
                          (first t))))))
