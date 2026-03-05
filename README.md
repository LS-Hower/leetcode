# leetcode
My LeetCode solutions

## Themes

e.g. calculating square root sum.

`esoteric`:

```Python
sqrt_sum = lambda ls: (lambda f: f(f, 0))(lambda me, ind: 0 if ind == len(ls) else me(me, ind + 1) + ls[ind] ** 0.5)
```

Sometimes use [JSFuck](https://github.com/aemkei/jsfuck).

Sometimes write binary code (generated with `objdump`) in C code.

`elegant`:

```Python
def sqrt_sum(ls: list[float]) -> float:
    return sum(x ** 0.5 for x in ls)
```

`traditional`:

```Python
def sqrt_sum(ls: list[float]) -> float:
    sigma = 0
    for x in ls:
        sigma += x ** 0.5
    return sigma
```
