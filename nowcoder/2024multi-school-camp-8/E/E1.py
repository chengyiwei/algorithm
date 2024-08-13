def S(x):
    res = 0
    while x:
        res += x % 10
        x //= 10
    return res

def solve(n):
    n_ = n
    siz = 0
    tp = 0
    t = 0
    while n:
        tp += tp % 10
        if n < 10:
            t = n
        n //= 10
        siz += 1
    tp = max(tp, (siz - 1) * 9 + t - 1)
    ans = 0
    n = n_
    l = 1
    r = 0
    while l <= n:
        r = n // (n // l)
        Up = n // l
        Dn = (n - tp + r - 1) // r
        if Up >= Dn:
            for m in range(Dn, Up + 1):
                Sm = S(m)
                if Sm < m and (n - Sm) % m == 0 and l <= (n - Sm) // m <= r:
                    ans += 1
        l = r + 1
    return ans

if __name__ == "__main__":
    T = int(input())
    results = []
    for _ in range(T):
        n = int(input())
        results.append(solve(n))
    for result in results:
        print(result)
