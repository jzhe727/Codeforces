# import math
import heapq
import sys

mod = 998244353

input = sys.stdin.readline
n, m = map(int, input().split())

seq = [ch for ch in input()[:-1]]

# le = seq.count("<")
# ge = seq.count(">")

# lei = [i for i in range(n) if seq[i] == "<"]
# gei = [i for i in range(n) if seq[i] == ">"]

# heapq.heapify(lei)
# heapq.heapify(gei)

# marks = le + ge

fact = 1
# c = n - marks
for i in range(1, n - 1):
    if seq[i] == "?":
        fact *= i
        fact %= mod


if seq[0] == "?":
    print(0)
else:
    print(fact)


for _ in range(m):
    astr, b = input().split()
    a = int(astr)
    a -= 1
    if b != "?" and seq[a] == "?":
        if a != 0:
            fact *= pow(a, -1, mod)
            fact %= mod
    elif b == "?" and seq[a] != "?":
        if a != 0:
            fact *= a
            fact %= mod
    seq[a] = b
    if seq[0] == "?":
        print(0)
    else:
        print(fact)
