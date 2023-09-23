a = input().split()
fas = input().split()
ass = input().split()
k = int(a[-1])
fas.sort(key=lambda x: int(x))
ass.sort(key=lambda x: int(x))
le = len(ass)
lee = len(fas)
i = 0
j = 0
c = 0
while True:
    if j == le or i == lee:
        break
    elif int(ass[j]) < int(fas[i])-k:
        j += 1
        continue
    elif int(ass[j]) > int(fas[-1])+k:
        break
    elif int(ass[j]) >= int(fas[i])-k and int(ass[j]) <= int(fas[i])+k:
        i += 1
        j += 1
        c += 1
        continue
    else:
        i += 1
print(c)
