# Python 脚本实现

# 检查一个三位数是否所有位数字都在 [0, 5]
def digits_within_range(number):
    return all(0 <= int(d) <= 5 for d in str(number))

# 存储结果
results = []

# 遍历所有可能的鸡和兔的只数
for x in range(100, 500):  # x 和 y 的脚数必须是三位数
    chicken_legs = 2 * x  # 鸡脚数
    rabbit_legs = 4 * x  # 兔脚数
    if (
        100 <= chicken_legs <= 999 and digits_within_range(chicken_legs) and
        100 <= rabbit_legs <= 999 and digits_within_range(rabbit_legs)
    ):
        # 满足条件，记录解
        results.append((x, x, chicken_legs, rabbit_legs))

# 排序结果（从小到大）
results.sort()

# 输出结果
results
