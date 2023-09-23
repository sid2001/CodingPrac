n = int(input())
ls = []
sum = 0
ls = list(int(x) for x in input().split())
for ii in ls:
    sum = sum + ii

s = 0
for ii in range(1, n+1):
    s = s + int(ii)

print(s-sum)
