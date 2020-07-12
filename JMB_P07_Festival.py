c = int(input())
mine = []
res = []
for a in range(c):
    n, l = map(int, input().split())
    ans = 100000000.0
    mine = list(map(int, input().split()))
    for i in range(0, n - l + 1):
        day = 1
        tmp = 0
        for j in range(i, n):
            tmp += mine[j]

            if day >= l:
                ans = min(ans, tmp/day)
            day += 1

    print('%.8f' % ans)
