from sys import stdin, stdout


def solution(arr):
    sol, _max, _min  = arr[0], arr[0], arr[0]

    for v in arr[1:]:
        if v < 0:
            _max, _min = _min, _max

        _max = max(v * _max, v)
        _min = min(v * _min, v)
        sol = max(_max, sol)

    return sol

def main():
    for line in stdin:
        print(solution(list(map(int,line.split()))[:-1]))

if __name__ == "__main__":
    main()
