N = int(input())
a = list(map(int, input().split()))
count = [0] * (N + 1)
for num in a:
    count[num] += 1

ans = 0
sum = 0
for i in range(1, N + 1):
    sum += count[i] * (count[i] - 1) // 2

for i in range(1, N + 1):
    ans += (sum - (count[i] * (count[i] - 1) // 2)) * count[i]

print(ans)