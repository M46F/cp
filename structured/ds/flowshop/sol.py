M, N = [int(x) for x in input().split()]

arr = []

for r in range(M):
    arr.append([int(x) for x in input().split()])
    if r == 0:
        for c in range(len(arr[r])):
            if c > 0:
                arr[r][c] += arr[r][c-1]
    else:
        for c in range(len(arr[r])):
            if c > 0:
                arr[r][c] += max(arr[r-1][c], arr[r][c-1])
            else:
                arr[r][c] += arr[r-1][c]
print(" ".join([str(row[-1]) for row in arr]))
