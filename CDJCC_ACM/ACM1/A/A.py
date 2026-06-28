n = int(input())
while True:
    try:
        lin = input()
    except :
        break
    if "." in lin:
        numbers = list(map(float, lin.split()))
        print(" ".join(map(lambda x: f"{x:.2f}", sorted(numbers))) + " ")
    else :
        numbers = list(map(int, lin.split()))
        print(" ".join(map(str, sorted(numbers))) + " ")