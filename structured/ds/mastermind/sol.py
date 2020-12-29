

x = input()

_, a,b = x.split()

r, s = 0, 0

d1, d2 = dict(), dict()

for i, c in enumerate(a):
    if c == b[i]:
        r += 1
    else:
        if c not in d1:
            d1[c] = 0
        if b[i] not in d2:
            d2[b[i]] = 0
        d1[c] += 1
        d2[b[i]] += 1

for c1 in d1:
    if c1 in d2:
        tmp = min(d1[c1], d2[c1])
        s += tmp
        d1[c1] -= tmp
        d2[c1] -= tmp

print(f"{r} {s}")
