t = int(input())
for _ in range(t):
    n = int(input())
    ans = [0] * (n + 1)
    vis = [0] * (n + 1)
    p = [k-1 for k in map(int, input().split())]
    s = input()
    for i in range(0, n):
        if vis[i]:
            continue
        cnt = 0
        while not vis[i]:
            vis[i] = 1
            cnt += s[i] == '0'
            i = p[i]
        while vis[i] != 2:
            ans[i] = cnt
            vis[i] = 2
            i = p[i]
    print(" ".join(map(str, ans[:-1])))