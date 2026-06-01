(define (char-minus c1 c2)
  (- (char->integer c1)
     (char->integer c2)))

(define/contract (number-of-special-chars word)
  (-> string? exact-integer?)
  (let ([lower (make-vector 26 #f)]
        [upper (make-vector 26 #f)])
    (for ([ch (in-string word)])
      (if (char-lower-case? ch)
          (vector-set! lower (char-minus ch #\a) #t)
          (vector-set! upper (char-minus ch #\A) #t)))
    (vector-count identity
                  (vector-map (lambda (a b) (and a b))
                              lower
                              upper))))
