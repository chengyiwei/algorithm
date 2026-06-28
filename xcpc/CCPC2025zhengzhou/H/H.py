n = int(input())
for i in range(n):
    s, l, r = map(int, input().split())
    print(r - l + 1)