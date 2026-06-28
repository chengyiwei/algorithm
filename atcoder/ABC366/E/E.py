N, D = map(int, input().split())
x = [0] * N
y = [0] * N
for i in range(N):
    x[i], y[i] = map(int, input().split())
M = 2 * 10 ** 6


def calc(x):
    xsum = [0] * (2 * M + 1)
    x.sort()
    i = 0
    xsum[-M] = sum(x) + N * M
    for j in range(-M + 1, M + 1):
        while i < N and x[i] < j:
            i += 1
        xsum[j] = xsum[j - 1] + 2 * i - N
    return xsum

xsum = calc(x)
ysum = calc(y)
ans = 0
xsum.sort()
ysum.sort()
j = 0
for i in range(2 * M + 1)[::-1]:
    while j < 2 * M + 1 and xsum[i] + ysum[j] <= D:
        j += 1
    ans += j
print(ans)