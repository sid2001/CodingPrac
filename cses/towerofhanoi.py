n = int(input())
lis = []


def tow(n, A, C, B):
    global c
    if n == 1:
        lis.append((A, C))
        return
    tow(n-1, A, B, C)
    lis.append((A, C))
    tow(n-1, B, C, A)


tow(n, 1, 3, 2)
print(len(lis))
for i, j in lis:
    print(i, j)
