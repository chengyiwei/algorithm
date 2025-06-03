N = int(input())

a = list(map(int, input().split()))

INF = 0x3f3f3f3f3f3f3f3f

M = max(a)
cnt = [-INF] * (M + 1)

ans = INF
for i in range(N):
    ans = min(ans, i - cnt[a[i]] + 1)
    cnt[a[i]] = i

if ans == INF:
    ans = -1
print(ans)