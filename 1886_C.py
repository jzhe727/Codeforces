import sys

input = sys.stdin.readline
test = int(input())
ans = ""
for _ in range(test):
    st = input()[:-1]
    pos = int(input())
    n = len(st)
    remove = [False for _ in st]
    prev = [i - 1 for i in range(n)]
    pos -= 1
    count = -1
    cl = n + 1
    while pos >= 0 and cl > 0:
        cl -= 1
        pos -= cl
        count += 1
    # remove count from st
    pos += cl
    i = 0
    j = 1
    while count > 0 and j < n:
        # while j < n and st[j] == st[i]:
        #     j += 1
        # if j == n:
        #     break
        if st[j] < st[i]:
            remove[i] = True
            prev[j] = prev[i]
            i = prev[i]
            count -= 1
            if i == -1:
                i = j
                j += 1
        else:
            i = j
            j += 1
    while count > 0:
        remove[i] = True
        i = prev[i]
        count -= 1
    new_st = [st[i] for i in range(n) if not remove[i]]

    ans += new_st[pos]

print(ans)
