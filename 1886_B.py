import sys

input = sys.stdin.readline

test = int(input())
for _ in range(test):
    px, py = map(int, input().split())
    ax, ay = map(int, input().split())
    bx, by = map(int, input().split())

    ap2 = (ax - px) ** 2 + (ay - py) ** 2
    ao2 = (ax) ** 2 + (ay) ** 2
    bp2 = (bx - px) ** 2 + (by - py) ** 2
    bo2 = (bx) ** 2 + (by) ** 2
    ab2 = (ax - bx) ** 2 + (ay - by) ** 2

    r1 = max(ap2, ao2) ** 0.5
    r2 = max(bp2, bo2) ** 0.5
    r3 = max(min(ao2, bo2), min(ap2, bp2), ab2 / 4) ** 0.5
    print(min(r1, r2, r3))
