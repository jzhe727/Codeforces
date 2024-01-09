import sys
t = int(input())
for _ in range(t):
    n = int(input())
    wl = input().split()
    pair = []
    for w in wl:
        if len(w) == n//2:
            pair.append(w)
    flag = False
    if pair[0] == pair[1][::-1]:
        flag = True
    if flag:
        print("Yes")
    else:
        print("No")
