c = int(input())
mine = []
res = []
while c > 0:
    n = int(input())
    l = int(input())
    ans = 100.0  # 정답을 넣을 변수
    for i in range(n):
        tmp = int(input())
        mine.append(tmp)
    for i in range(l, n + 1):  # 팀 개수
        for j in range(n - i + 1):  # 시작 날짜
            sliced = mine[j:j+i]
            tmpres = sum(sliced) / i
            ans = min(ans, tmpres)
    c -= 1
    res.append(ans)
for i in range(len(res)):
    print(res[i])
