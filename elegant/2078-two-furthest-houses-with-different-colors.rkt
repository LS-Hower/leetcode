(define/contract (max-distance colors)
  (-> (listof exact-integer?) exact-integer?)
  (let ([rev-colors (reverse colors)])
    (let* ([n (length colors)]
           [left (first colors)]
           [right (first rev-colors)]
           [l (index-where colors (lambda (c) (not (= c right))))]
           [r (index-where rev-colors (lambda (c) (not (= c left))))])
      (- n 1 (min l r)))))
