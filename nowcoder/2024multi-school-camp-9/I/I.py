from math import ceil, floor, sqrt

def check (x):
    xq = int(sqrt(x))
    return xq * xq == x

def calc(N, lenth):
    ret = 0
    high = N // (10 ** (lenth // 2))
    low = N % (10 ** (lenth // 2))
    ret = ceil(sqrt(high)) * ceil(sqrt(10 ** (lenth // 2)))

    if check(high):
        ret += floor(sqrt(low)) + 1
    
    return ret


n = int(input())
l, r = map(int, input().split())

lenth = len(str(r))
ans = calc(r, lenth) - calc(l - 1, lenth)
print(ans)
