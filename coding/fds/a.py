n = int(input())
s = input()

count_BB = s.count("BB")
count_EE = s.count("EE")

excitement_levels = set()

for i in range(n):
    if s[i] == "F":
        s_B = s[:i] + "B" + s[i+1:]
        s_E = s[:i] + "E" + s[i+1:]
        count_BB_B = s_B.count("BB")
        count_EE_B = s_B.count("EE")
        count_BB_E = s_E.count("BB")
        count_EE_E = s_E.count("EE")
        excitement_levels.add(count_BB_B + count_EE_B)
        excitement_levels.add(count_BB_E + count_EE_E)

excitement_levels = sorted(list(excitement_levels))
print(len(excitement_levels))
for level in excitement_levels:
    print(level)