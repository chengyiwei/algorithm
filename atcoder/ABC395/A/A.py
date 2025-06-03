N = int(input())
a = list(map(int, input().split()))

flg = True
for i in range(1, N):
    if a[i - 1] >= a[i]:
        print('No')
        flg = False
        break

if flg:
    print('Yes')

