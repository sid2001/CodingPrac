nu = int(input())
num = nu
sum = num*(num + 1)/2
c1 = 0
if sum % 2 != 0:
    print("NO")
else:
    print("YES")
    ar = list(range(1, nu+1))
    c = nu-1
    n1 = []
    n2 = []
    su = sum/2
    while su != 0:
        if su-num >= 0:
            su -= num
            n1.append(ar[num-1])
            ar.pop()
            c1 += 1
        else:
            n2.append(ar[num-1])
            ar.pop()
        c -= 1
        num -= 1
    n2 += ar
    print(c1)
    print(*n1)
    print(nu-c1)
    print(*n2)
