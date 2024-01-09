import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n = int(input())
    arr = list(map(int, input().split()))
    if arr[0] == 1:
        arr[0] += 1
    for i in range(n-1):
        if arr[i+1] == 1:
            arr[i+1] += 1
        if arr[i+1]%arr[i] == 0:
            arr[i+1] += 1
    print(' '.join(map(str, arr)))