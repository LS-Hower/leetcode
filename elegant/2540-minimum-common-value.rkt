(define #|/contract|# (get-common nums1 nums2)
  ;(-> (listof exact-integer?) (listof exact-integer?) exact-integer?)
  (if (or (null? nums1) (null? nums2))
      -1
      (let ([h1 (first nums1)]
            [h2 (first nums2)])
        (cond [(< h1 h2)
               (get-common (rest nums1) nums2)]
              [(> h1 h2)
               (get-common nums1 (rest nums2))]
              [else
               h1]))))
