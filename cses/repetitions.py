s = input()
s = list(s)
s.append('False')
c1 = 1
c2 = 0

for a, ii in enumerate(s):
    if s[a] != 'False':
        if s[a] == s[a+1]:
            c1 = c1 + 1
        else:
            if c1 >= c2:
                c2 = c1
            c1 = 1
print(c2)
