import time

n = int(input())
start = time.time()
trunc = (1 << 200_000) - 1
r = 1
for i in range(n):
    # r |= (r * 2**i) & trunc
    r |= r << i & trunc
end = time.time()
# print(bin(r))
print(end - start)
