num = int(input())
c = 1
n = 0

while int(num/(5**c)) >= 1:
    n += int(num/(5**c))
    c += 1
print(n)
