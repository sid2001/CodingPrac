# a = input().split()
# w = [int(x) for x in input().split()]
# n = int(a[0])

# cap = int(a[1])
# ar = [0]*(cap+1)
# w.sort()
# ww = []

# for i in w:
#     ar[i] += 1
#     if ar[i] == 1:
#         ww.append(i)

# i = 0
# g = 0
# k = len(ww)-1

# while True:
#     if i > k:
#         break
#     if ww[k]+ww[i] > cap:
#         g += ar[ww[k]]
#         ar[ww[k]] = 0
#         k -= 1
#     elif ww[k]+ww[i] == cap and ar[ww[i]] > 0 and ar[ww[k]] > 0:
#         if ar[ww[i]] == ar[ww[k]] and i == k:
#             g += ar[ww[i]]//2 + ar[ww[i]] % 2
#             break
#         elif ar[ww[i]] == ar[ww[k]]:
#             g += ar[ww[i]]
#             i += 1
#             k -= 1
#             ar[ww[i]], ar[ww[k]] = 0, 0
#         elif ar[ww[i]] < ar[ww[k]]:
#             g += ar[ww[i]]
#             ar[ww[k]] -= ar[ww[i]]
#             ar[ww[i]] = 0
#             i += 1
#         else:
#             g += ar[ww[k]]
#             ar[ww[i]] -= ar[ww[k]]
#             ar[ww[k]] = 0
#             k -= 1
#     elif ww[k]+ww[i] < cap and ar[ww[i]] > 0 and ar[ww[k]] > 0:
#         g += 1
#         if ar[ww[i]] == 1:
#             ar[ww[i]] -= 1
#             i += 1
#         else:
#             ar[ww[i]] -= 1
#         if ar[ww[k]] == 1:
#             ar[ww[k]] -= 1
#             k -= 1
#         else:
#             ar[ww[k]] -= 1
# print(g)
a = input().split()
w = [int(x) for x in input().split()]
n = int(a[0])
w.sort()
cap = int(a[1])
ar = [False]*n
w.sort()
i = 0
j = len(w)-1
g = 0
while i < j:
    if w[i]+w[j] > cap:
        j -= 1
    else:
        ar[i], ar[j] = True, True
        g += 1
        i += 1
        j -= 1
for i in ar:
    if not i:
        g += 1
print(g)
