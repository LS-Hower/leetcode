(define/contract (length-of-longest-substring s)
  (-> string? exact-integer?)
  (let f ([s s]
          [l 0]
          [r 0]
          [chars (set)]
          [best 0])
    (let ([new-best (max best (- r l))])
      (if (= r (string-length s))
          new-best
          (let ([head (string-ref s l)]
                [next (string-ref s r)])
            (cond [(not (set-member? chars next))
                   (f s l (add1 r) (set-add chars next) new-best)]
                  [(char=? head next)
                   (f s (add1 l) (add1 r) chars new-best)]
                  [else
                   (f s (add1 l) r (set-remove chars head) new-best)]))))))
