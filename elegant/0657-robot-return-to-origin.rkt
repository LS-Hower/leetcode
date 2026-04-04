(require srfi/13)

(define (judge-circle moves)
  (and (= (string-count moves #\L) (string-count moves #\R))
       (= (string-count moves #\U) (string-count moves #\D))))
