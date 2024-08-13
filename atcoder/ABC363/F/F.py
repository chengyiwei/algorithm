import math
import functools

@functools.cache
def f(N):
    if not "0" in str(N) and str(N) == str(N)[::-1]:
        return str(N)
    for x in range(2, int(math.sqrt(N)) + 1):
        if N % x == 0 and not "0" in str(x):
            y = int(str(x)[::-1])
            if N // x % y == 0 and len(f(N // x // y)) != 0:
                return str(x) + "*" + f(N // x // y) + "*" + str(y)
    return ""

N = int(input())
print("-1" if len(f(N)) == 0 else f(N))
