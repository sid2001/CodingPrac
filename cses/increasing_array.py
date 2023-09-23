length = int(input())

ls = list(int(x) for x in input().split())
c = 0
for a in range(len(ls)-1):
    d = ls[a]-ls[a+1]
    if (d) > 0:
        ls[a+1] = ls[a+1]+d
        c = c+d


print(c)
