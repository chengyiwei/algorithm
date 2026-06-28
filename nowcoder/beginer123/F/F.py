import sys

def main():
    input = sys.stdin.read
    data = input().split()
    t = int(data[0])
    idx = 1
    MX = 10**12
    results = []
    
    for _ in range(t):
        x = int(data[idx]); idx += 1
        y = int(data[idx]); idx += 1
        k = int(data[idx]); idx += 1
        
        if y == 1:
            results.append("-1")
            continue
        
        q = y - 1
        a = k
        n = x
        
        while n > 0:
            m = (a - 1) // q
            r = (a - 1) % q
            
            if m == 0:
                a = a + m
                break
            
            t_val = (q - r + m - 1) // m
            if t_val > n:
                t_val = n
            
            a += m * t_val
            n -= t_val
            
            if a > MX:
                results.append("-1")
                break
        else:
            results.append(str(a))
    
    print("\n".join(results))

if __name__ == "__main__":
    main()