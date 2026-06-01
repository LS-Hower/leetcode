(require racket/case)

(define (char-minus c1 c2)
  (- (char->integer c1)
     (char->integer c2)))

(define (char-upper/index ch)
  (let ([upper (char-upper-case? ch)])
    (values upper
            (char-minus ch (if upper #\A #\a)))))

(define (vector-modify! v ind transform)
  (vector-set! v ind (transform (vector-ref v ind))))

(define (transform upper state)
  (case/eq state
   [(start) (if upper 'locked 'lower)]
   [(lower) (if upper 'lower-upper 'lower)]
   [(lower-upper) (if upper 'lower-upper 'locked)]
   [(locked) 'locked]))

(define/contract (number-of-special-chars word)
  (-> string? exact-integer?)
  (let ([states (make-vector 26 'start)])
    (for ([ch (in-string word)])
      (let-values ([(up ind) (char-upper/index ch)])
        (vector-modify! states ind (curry transform up))))
    (vector-count (curry eq? 'lower-upper) states)))