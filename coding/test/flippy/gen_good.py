import random
from random import sample

for i in range(4, 11):
    filename = f"input{i:02}.txt"
    with open (filename, "w") as f:
        length = random.randint(10, 100000)
        ordered_list = [i for i in range(1, length + 1)]

        # sample from first half indices to flip
        sample_from = [i for i in range(1, length//2 + 1)]
        to_flip = sample(sample_from, random.randint(1, length//2))  

        print(length, file = f)

        with open (f"output{i:02}.txt", "w") as f1:
            print(f"{len(to_flip)}", file = f1, end = "")
        
        for j in to_flip:
            temp = ordered_list[j - 1]
            ordered_list[j - 1] = ordered_list[length - j]
            ordered_list[length - j] = temp

        print(*ordered_list, sep = ' ', file = f, end = "")