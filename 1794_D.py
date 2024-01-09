#sieve later
# primes = []
def isPrime(n):
    if n == 1:
        return False
    if n % 2 == 0 and n != 2:
        return False
    for i in range(3, 1000, 2):
        if n % i == 0 and n != i:
            return False
    return True

MOD = 998244353
def product(s, e): #end inclusive
    res = 1
    for i in range(s, e+1):
        res *= i
        res %= MOD
    return res

n = int(input())
set = list(map(int, input().split()))
# set.sort()
primes = {}
comp = {}
#prime_total = 0
for a in set:
    if isPrime(a):
        #prime_total += 1
        if a not in primes:
            primes[a] = 1
        else:
            primes[a] += 1
    else:
        if a not in comp:
            comp[a] = 1
        else:
            comp[a] += 1
if len(primes) < n:
    print(0)
    exit(0)
primes = [(k, v) for k, v in primes.items()]
comp = [v for v in comp.values()]
#calculate factorial
def product(s, e): #s, e inclusive
    res = 1
    while s <= e:
        res *= s
        res %= MOD
        s += 1
    return res
def inv(n):
    return pow(n, -1, MOD)

def choose(n, a): #n choose a
    if (n-a < a):
        a = n-a
    return (product(n-a+1, n) * inv(product(1, a)))%MOD

mem = [[-1 for _ in range(n+1)] for _ in range(len(primes)+1)] 
stack = [] #store tuples which are function inputs
stage = [] #store which part the function is in
ret1 = [] # store the result of the first return
res = -1
stack.append((n, n)) #number of primes, amount of space left
stage.append(0)
ret1.append(-1)
while stack:
    i = len(stack)
    p, s = stack[-1]
    if i <= len(primes):
        _, am = primes[i-1]
    # print(i)
    if stage[-1] == 0:
        if s < 0:
            stage.pop()
            stack.pop()
            ret1.pop()
            res = 0
            # print(p, s, i, res)
        elif p < 0:
            stage.pop()
            stack.pop()
            ret1.pop()
            res = 0
            # print(p, s, i, res)
        elif i == len(primes) + 1:
            stage.pop()
            stack.pop()
            ret1.pop()
            if p == 0:
                res = 1
            else:
                res = 0
            # print(p, s, i, res)
        elif mem[i][s] != -1: #p+s is constant for each row, only need s for uniqueness
            stage.pop()
            stack.pop()
            ret1.pop()
            res = mem[i][s]
            # print(p, s, i, res)
        else:
            stage[-1] += 1
            stage.append(0)
            stack.append((p-1, s-(am-1))) #first call: use this prime
            ret1.append(-1)
    elif stage[-1] == 1:
        ret1[-1] = (res * choose(s, (am-1)))%MOD
        stage[-1] += 1
        stage.append(0)
        stack.append((p, s-am)) #second call: don't use this prime
        ret1.append(-1)
    elif stage[-1] == 2:
        ret2 = (res * choose(s, am))%MOD
        res = (ret1[-1] + ret2)%MOD
        mem[i][s] = res
        stage.pop()
        stack.pop()
        ret1.pop()
        # print(p, s, i, res)

res = (res * product(1, sum(comp)))%MOD
for v in comp:
    res *= inv(product(1, v))
    res %= MOD

print(res)
#get all (pure number of primes) combinations, minus the number of ways which we could have duplicate primes)
