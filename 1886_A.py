test = int(input())
for _ in range(test):
    n = int(input())
    if n % 3 == 0:
        x = 1
        y = 4
        z = n - 5
        if z == y or z == x or z <= 0:
            print("NO")
        else:
            print("YES")
            print(x, y, z)
    elif n % 3 == 1:
        x = 1
        y = 2
        z = n - 3
        if z == 1 or z <= 0:
            print("NO")
        else:
            print("YES")
            print(x, y, z)
    elif n % 3 == 2:
        x = 1
        y = 2
        z = n - 3
        if z == 2 or z <= 0:
            print("NO")
        else:
            print("YES")
            print(x, y, z)
    # if n <= 6 or n == 8:
    #     print("NO")
    # else:
    #     print("YES")
    #     if n%3 == 0:
