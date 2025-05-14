# st = input()
# di = dict()
# for i in st:
#     if di.get(i):
#         di[i] += 1
#     else:
#         di[i] = 1
# if len(st) % 2 == 0:
#     ar = [0]*len(st)
#     c = 0
#     for key, value in di.items():
#         if value % 2 != 0:
#             print("NO SOLUTION")
#             exit()
#         else:
#             for i in range(int(value/2)):
#                 ar[c], ar[-(c+1)] = key, key
#                 c += 1
# else:
#     ar = [0]*len(st)
#     c = 0
#     for key, value in di.items():
#         while value > 0:
#             if value == 1:
#                 if ar[len(ar)//2] == 0:
#                     ar[len(ar)//2] = key
#                     value -= 1
#                 else:
#                     print("NO SOLUTION")
#                     exit()
#             else:
#                 for i in range(int(value/2)):
#                     ar[c], ar[-(c+1)] = key, key
#                     c += 1
#                     value -= 2
# print("".join(ar))

s = input()
n = len(s)
l = [0]*26
for i in range(n):
    l[ord(s[i])-97] += 1
if (sum(x % 2 for x in l) > 1):
    print("NO SOLUTION")
t = ""
for i in range(26):
    t += chr(65+i)*(l[i]//2)
for i in range(26):
    if (l[i] % 2):
        t += chr(65+i)
for i in range(25, -1, -1):
    t += chr(65 + i)*(l[i]//2)
print(t)
