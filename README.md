# leetcode
My LeetCode solutions

## Themes

e.g. calculating square root sum.

`esoteric`:

```Python
sqrt_sum = lambda ls: (lambda f: f(f, 0))(lambda me, ind: 0 if ind == len(ls) else me(me, ind + 1) + ls[ind] ** 0.5)
```

`generator`:

```Python
def sqrt_sum(ls: list[float]) -> float:
    return sum(x ** 0.5 for x in ls)
```

`racket`:

```Racket
(define (sqrt-sum ls)
    (apply + (map (lambda (x) (sqrt x)) ls)))
```

or

```Racket
(define (sqrt-sum ls)
    (define (iter nums acc)
        (if (null? nums)
            acc
            (iter (cdr nums) (+ acc (sqrt (car nums))))))
    (iter ls 0))
```

`ranges`:

```C++ 20
double sqrt_sum(const vector<double>& ls)
{
    return ranges::fold_left(
        ls,
        0,
        [](auto sum, auto x) { return sum + sqrt(x); }
    );
}
```

`traditional`:

```C++
double sqrt_sum(const vector<double>& ls)
{
    double sum = 0;
    for (const auto x : ls) {
        sum += sqrt(x);
    }
    return sum;
}
```
