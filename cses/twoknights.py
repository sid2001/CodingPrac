num = int(input())


for i in range(1, num+1):
    n = i**2
    print(int(((n**2 - n)/2)-(4*(i-1)*(i-2))))
