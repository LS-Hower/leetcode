(define/contract (rotate-string s goal)
  (-> string? string? boolean?)
  (and (= (string-length s) (string-length goal))
       (string-contains? (string-append goal goal) s)))
