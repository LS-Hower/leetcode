(require srfi/41)

(define (dec-shr num)
  (quotient num 10))

(define (all-prefixes num)
  (stream->list
   (stream-take-while
    positive?
    (stream-iterate dec-shr
                    num))))

(define (longest-valid-prefix prefix-set num)
  (findf (curry set-member? prefix-set)
         (all-prefixes num)))

(define (num-length num)
  (if (< num 10)
      1
      (add1 (num-length (dec-shr num)))))

(define (longest-valid-prefix-length prefix-set num)
  (let ([prefix (longest-valid-prefix prefix-set num)])
    (if prefix
        (num-length prefix)
        0)))

(define #|/contract|# (longest-common-prefix arr1 arr2)
  ;@(-> (listof exact-integer?) (listof exact-integer?) exact-integer?)
  (let ([prefixes1 (list->set (apply append
                                     (map all-prefixes arr1)))])
    (apply max
           (map (curry longest-valid-prefix-length prefixes1)
                arr2))))
