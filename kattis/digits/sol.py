

while True:
    x = input()
    if x == 'END':
        break
    else:
        out = 1
        newx = str(len(x))
        while newx != x:
            x = newx
            newx = str(len(newx))
            out += 1
        print(out)
