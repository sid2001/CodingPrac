a = input().split()
tn = int(a[0])
cn = int(a[1])

tp = [int(x) for x in input().split()]
cp = [int(x) for x in input().split()]
tp.sort()
cp1 = sorted(cp)
ar = [-1]*(cp1[-1]+1)

i = len(cp1)-1
j = len(tp)-1

while j >= 0 and i >= 0:
    if cp1[i] >= tp[j]:
        ar[cp1[i]] = tp[j]
        j -= 1
        i -= 1
    else:
        j -= 1

for i in cp:
    print(ar[i])
