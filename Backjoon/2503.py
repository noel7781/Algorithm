from itertools import combinations, permutations

def checkOk(info, num):
    check_ball_cnt = 0
    check_strike_cnt = 0
    for i in range(3):
        for j in range(3):
            if num[i] == int(info[0][j]):
                if i == j:
                    check_strike_cnt += 1
                else:
                    check_ball_cnt += 1
    return info[1] == check_strike_cnt and info[2] == check_ball_cnt

N = int(input())
infos = []
for _ in range(N):
    number, strike_cnt, ball_cnt = map(int, input().split())
    infos.append([str(number), strike_cnt, ball_cnt])

ans = 0
lst = [i for i in range(1, 10)]
for cand in permutations(lst, 3):
    tmp = 1
    for info in infos:
        if checkOk(info, cand) is False:
            tmp = 0
            break
    ans += tmp
print(ans)