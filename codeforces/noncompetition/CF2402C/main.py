T = int(input())
for _ in range(T):
    n, k = map(int, input().split())
    s = input()
    sum = 0 # 后缀和
    p = []
    for i in range(n - 1, 0 , -1):
        if s[i] == '0':
            sum -= 1
        else:
            sum += 1
        p.append(sum)
    p.sort()
    len_p = len(p)
    ans = 1
    while k > 0 and len_p > 0:
        k -= p[len_p - 1]
        len_p -= 1
        ans += 1
    
    if k > 0:
        print(-1)
    else:
        print(ans)
    