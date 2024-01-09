t = int(input())
for _ in range(t):
    n = int(input())
    arr = list(map(int, input().split()))
    e = 1 #exclusive
    # total = 0
    s = 0
    ans = []
    while e < n+1:
        while s > 0:
            if arr[s-1] >= e-s+1:
                s -= 1
            else:
                break
        ans.append(e-s)
        e += 1
        s += 1    
    print(' '.join(map(str, ans)))
