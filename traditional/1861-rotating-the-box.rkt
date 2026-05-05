(define (transpose matrix)
  (apply map list matrix))

(define (rotate-90-clockwise matrix)
  (transpose (reverse matrix)))

(define (list-split ls sep)
  (let ([ind (index-of ls sep)])
    (if ind
        (let-values ([(head tail-splice)
                      (split-at ls ind)])
          (cons head (list-split (rest tail-splice)
                                 sep)))
        (list ls))))

(define (list-join lss sep)
  (define (process-non-null lss)
    (append (first lss)
            (if (empty? (rest lss))
                null
                (cons sep
                      (process-non-null (rest lss))))))
  (if (empty? lss)
      null
      (process-non-null lss)))

(define #|/contract|# (rotate-the-box boxGrid)
  #|(-> (listof (listof char?)) (listof (listof char?)))|#
  (define (process-row row)
    (let* ([parts (list-split row #\*)]
           [processed-parts (map process-part parts)])
      (list-join processed-parts #\*)))
  (define (process-part part)
    (let* ([stone-count (count (curry char=? #\#) part)]
           [air-count (- (length part) stone-count)]
           [stone (build-list stone-count (const #\#))]
           [air (build-list air-count (const #\.))])
      (append air stone)))
  (rotate-90-clockwise (map process-row boxGrid)))
