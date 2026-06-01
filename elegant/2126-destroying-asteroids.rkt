(define/contract (asteroids-destroyed mass asteroids)
  (-> exact-integer? (listof exact-integer?) boolean?)
  (not (zero? (foldl (lambda (a m)
                       (if (m . < . a)
                           0
                           (+ m a)))
                     mass
                     (sort asteroids <)))))