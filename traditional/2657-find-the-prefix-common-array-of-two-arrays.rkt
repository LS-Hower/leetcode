(define (boolean->integer b)
  (if b 1 0))

(define/contract (find-the-prefix-common-array A B)
  (-> (listof exact-integer?) (listof exact-integer?) (listof exact-integer?))
  (let rec ([a A]
            [b B]
            [prev-a-appear (set)]
            [prev-b-appear (set)]
            [prev-same 0])
    (if (null? a)
        null
        (let* ([ah (first a)]
               [bh (first b)]
               [same (+ prev-same
                        (boolean->integer (set-member? prev-a-appear bh))
                        (boolean->integer (set-member? prev-b-appear ah))
                        (boolean->integer (= ah bh)))])
            (cons same
                  (rec (rest a)
                       (rest b)
                       (set-add prev-a-appear ah)
                       (set-add prev-b-appear bh)
                       same))))))
