; Definition for singly-linked list:
#|

; val : integer?
; next : (or/c list-node? #f)
(struct list-node
  (val next) #:mutable #:transparent)

; constructor
(define (make-list-node [val 0])
  (list-node val #f))

|#

(define (get-back-and-len head [len 1])
  (if (not (list-node-next head))
      (values head len)
      (get-back-and-len (list-node-next head) (add1 len))))

(define (get-nth head n)
  (if (= n 0)
      head
      (get-nth (list-node-next head) (sub1 n))))

(define #|/contract|# (rotate-right head k)
  ;(-> (or/c list-node? #f) exact-integer? (or/c list-node? #f))
  (if (not head)
      #f
      (let-values ([(back len) (get-back-and-len head)])
        (let ([rot (remainder k len)])
          (if (= rot 0)
              head
              (let* ([new-back-i (- len 1 rot)]
                     [new-back (get-nth head new-back-i)]
                     [new-head (list-node-next new-back)])
                (set-list-node-next! new-back #f)
                (set-list-node-next! back head)
                new-head))))))
