n = int(input())
a = []
for i in range(n):
    a.append(input().split())

for i in a:
    if (int(i[0]) + int(i[1])) % 3 != 0:
        print("NO")
        continue
    else:
        if 2*min(int(i[0]), int(i[1])) < max(int(i[0]), int(i[1])):
            print("NO")
            continue
        else:
            print("YES")
