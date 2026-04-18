(define/contract (max-distance nums1 nums2)
  (-> (listof exact-integer?) (listof exact-integer?) exact-integer?)
  (let transform ([i 0]
                  [ls1 nums1]
                  [j 0]
                  [ls2 nums2]
                  [best 0])
    (cond [(or (null? ls1) (null? ls2))
           best]
          [(not (<= i j))
           (transform i ls1 (add1 j) (rest ls2) best)]
          [(not (<= (first ls1) (first ls2)))
           (transform (add1 i) (rest ls1) j ls2 best)]
          [else
           (transform i ls1 (add1 j) (rest ls2) (max best (abs (- i j))))])))
