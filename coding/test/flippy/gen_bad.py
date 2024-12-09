import numpy as np
import random

for i in range(17, 21):
    filename = f"input{i}.txt"
    with open(filename, "w") as f:
        length = random.randint(10, 100000)
        print(length, file = f)
        perm = np.random.permutation(list(range(1, length + 1)))
        print(*perm, sep = ' ', file = f, end = "")

    with open(f"output{i}.txt", "w") as f1:
        print(-1, file = f1, end = "")