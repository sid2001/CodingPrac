
def spiraln():
    global c
    global k, x, y, max
    while (c <= max):
        if (c == 1):
            ls[x][y] = k
            k += 1
            c += 1
        else:
            if (c % 2 == 0):
                y += 1
                while (x <= y):
                    ls[x][y] = k
                    x += 1
                    k += 1
                x -= 1
                while (y > 0):
                    y -= 1
                    ls[x][y] = k
                    k += 1
            else:
                x += 1
                while (y <= x):
                    ls[x][y] = k
                    k += 1
                    y += 1
                y -= 1
                while (x > 0):
                    x -= 1
                    ls[x][y] = k
                    k += 1
            c += 1


c = 1
x = y = 0
k = 1
ran = int(input())
lis = []
lis2 = []
for ii in range(0, ran):
    lis = lis + [list((int(x) for x in input().split()))]
    #print(lis, lis2)

for i, j in lis:
    max = i if i > j else j
    ls = [[0 for i in range(max)] for j in range(max)]
    spiraln()
    print(ls[i-1][j-1])
