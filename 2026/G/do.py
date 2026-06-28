import os
import time

def make_data(x, name): # 造第 x 组数据
    now_path = "./data/" + name + str(x);
    print("正在造第" + str(x) + "组数据...")
    os.system("./make_data > " + now_path + ".in")
    time.sleep(0.5)
    os.system("./std" + "<" + now_path + ".in >" + now_path + ".out")
    print("第" + str(x) + "组数据造好了！")
    time.sleep(1)

def main():
    dn = int(input("输入需要造的起点："))
    up = int(input("输入需要造的终点："))
    name = "data"
    for i in range(dn, up + 1):
        make_data(i, name)

main()