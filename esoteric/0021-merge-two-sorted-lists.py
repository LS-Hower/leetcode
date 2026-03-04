def cat(x, y):
    x.next = y

class Solution:
    mergeTwoLists = lambda _, list1, list2: (lambda ls: (lambda f: f(f, ls, None))(lambda me, x, y: y if x is None else (lambda temp: (cat(x, y), me(me, temp, x))[-1])(x.next)))((lambda cases: cases(cases, None, list1, list2))(lambda me, acc, ls1, ls2: (lambda c1, c2: (acc if ls1 is None and ls2 is None else c2() if ls1 is None and ls2 is not None else c1() if ls1 is not None and ls2 is None else c1() if ls1.val <= ls2.val else c2()))(lambda: (lambda new_ls1: (cat(ls1, acc), me(me, ls1, new_ls1, ls2))[-1])(ls1.next), lambda: (lambda new_ls2: (cat(ls2, acc), me(me, ls2, ls1, new_ls2))[-1])(ls2.next))))
