# -*- coding: utf-8 -*-
def func(fmap, remain, n):
    minN = -1
    for i in range(n):
        if remain[i] == True:  # 남은 인원 중 가장 작은 번호 인원 찾기
            minN = i
            break
    # 기저 사례
    if minN == -1:
        return 1  # 남은 인원이 없음
    ans = 0

    # 조사
    for i in range(minN + 1, n):
        if remain[i] == True and fmap[minN][i] == True:
            remain[i] = remain[minN] = False
            ans += func(fmap, remain, n)
            remain[i] = remain[minN] = True
    return ans


c = int(input())
for _ in range(0, c):
    n, m = map(int, input().split())
    fList = list(map(int, input().split()))
    fmap = [[False for col in range(n)] for row in range(n)]
    for i in range(m):
        x = fList[2 * i]
        y = fList[2 * i+1]
        fmap[x][y] = True
        fmap[y][x] = True
    remain = [True for i in range(n)]
    print(func(fmap, remain, n))
