import random

N = 1000000007

def fib(n):
    if n <= 1:
        return n
    f = [None] * (n + 1)
    f[0] = 0
    f[1] = 1
    for i in range(2, n + 1):
        f[i] = (f[i - 1] + f[i - 2]) % N
    
    return f[n]

for i in range(6, 16):
    filename = f"input{i:02}.txt"
    with open (filename, "w") as f:
        length = random.randint(10, 100000)
        print(length, end = "", file = f)

        # print((fib(length + 1) % N))

        filename = f"output{i:02}.txt"

        with open (filename, "w") as f1:
            ans = ((fib(length + 1) % N) ** 2) % N
            print(ans, end = "", file = f1)
