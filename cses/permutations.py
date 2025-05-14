n = int(input())
ar = [-1]*n
nu = 1
if n != 3 and n != 2 and n != 4:
    for i in range(0, n, 2):
        ar[i] = nu
        nu += 1
    for i in range(1, n, 2):
        ar[i] = nu
        nu += 1
    for i in ar:
        print(f"{i} ", end="")
elif n == 4:
    print("2 4 1 3")
else:
    print("NO SOLUTION")
