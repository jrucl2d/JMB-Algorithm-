# -*- coding: utf-8 -*-

# 현재 point가 제일 왼쪽, 제일 위의 점이라고 가정했을 때 가능한 L자 도형을 이루는 point들
cover = [[[0, 0], [0, 1], [1, 0]],
         [[0, 0], [0, 1], [1, 1]],
         [[0, 0], [1, 0], [1, 1]],
         [[0, 0], [1, 0], [1, -1]]]


def func(matrix):
    found = False
    a = b = -1
    for i in range(len(matrix)):
        for j in range(len(matrix[0])):
            if matrix[i][j] == 0:  # 한 개라도 흰 색이 남아있다면 끝난것이 아니다.
                a, b = i, j  # 위치 복사
                found = True
                break
        if found == True:
            break
    # 기저사례
    if a == -1:
        return 1

    ans = 0
    limit1 = len(matrix)
    limit2 = len(matrix[0])
    for num in range(4):
        a1 = a + cover[num][1][0]
        b1 = b + cover[num][1][1]
        a2 = a + cover[num][2][0]
        b2 = b + cover[num][2][1]
        # 예외 사항 : matrix 범위 밖
        if a1 < 0 or b1 < 0 or a2 < 0 or b2 < 0 or a1 >= limit1 or a2 >= limit1 or b1 >= limit2 or b2 >= limit2:
            continue
        if matrix[a1][b1] == 0 and matrix[a2][b2] == 0:
            matrix[a][b] = matrix[a1][b1] = matrix[a2][b2] = 1
            ans += func(matrix)
            matrix[a][b] = matrix[a1][b1] = matrix[a2][b2] = 0

    return ans


c = int(input())
for _ in range(c):
    h, w = map(int, input().split())
    tmpmatrix = []  # 문자열
    matrix = [[0 for col in range(w)] for row in range(h)]  # 숫자
    for _1 in range(h):
        tmp = input()
        tmpmatrix.append(tmp)

    # 예외 사항. L자 모형으로 채울 수 없음
    cnt = 0
    for i in range(h):
        for j in range(w):
            if tmpmatrix[i][j] == '.':
                cnt += 1
                matrix[i][j] = 0  # 흰색은 0
            else:
                matrix[i][j] = 1  # 검은색은 1

    # 예외 사항
    if cnt % 3 != 0:
        print(0)
        continue
    print(func(matrix))
