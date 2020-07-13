# -*- coding: utf-8 -*-
# 스위치 정보
linkedClock = {0: [0, 1, 2], 1: [3, 7, 9, 11], 2: [4, 10, 14, 15], 3: [0, 4, 5, 6, 7], 4: [6, 7, 8, 10, 12], 5: [
    0, 2, 14, 15], 6: [3, 14, 15], 7: [4, 5, 7, 14, 15], 8: [1, 2, 3, 4, 5], 9: [3, 4, 5, 9, 13]}
INF = 987654312

# 아이디어 : 3시간씩 이동하는데 4번 누르면 다시 제자리로 돌아온다. 즉, 4번 이상 누를 일이 없다.
# 누르는 순서는 상관없다. 1,2,3 이던 3,2,1이던 같다.


def IsDone(arr):
    for i in arr:
        if i != 12:
            return False
    return True


def Push(num, arr):
    tmplen = len(linkedClock[num])
    for i in range(tmplen):
        arr[linkedClock[num][i]] += 3  # 누르는 동작 수행
        if arr[linkedClock[num][i]] == 15:
            arr[linkedClock[num][i]] = 3


def func(arr, swch):
    if swch[0] == 10:
        if IsDone(arr) == True:
            return 0
        else:
            return INF
    ans = INF
    for cnt in range(4):  # 누르는 횟수, 0~3
        n = swch[0] + 1
        tmp = []  # 다음 스위치로 넘기기 때문에 1을 더해줘야 함
        tmp.append(n)
        ans = min(ans, cnt+func(arr, tmp))
        Push(swch[0], arr)  # 현재 스위치를 누름
    return ans


c = int(input())
for _ in range(c):
    arr = list(map(int, input().split()))
    swch = [0]
    ans = func(arr, swch)
    if ans > INF - 10:
        print(-1)
    else:
        print(ans)
