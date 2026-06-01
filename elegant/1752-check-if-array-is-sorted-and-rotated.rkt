(define #|/contract|# (check nums)
  ;(-> (listof exact-integer?) boolean?)
  (<= (count false? (map <= (cons (last nums) (drop-right nums 1)) nums)) 1))
