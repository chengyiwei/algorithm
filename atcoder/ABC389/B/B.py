N = int(input())
for i in range(0, 10000):
    now = 1
    for j in range(1, i + 1):
        now *= j
    if now == N:
        print(i)
        exit()