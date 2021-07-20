#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

int tonum(char arr[]) {
    int res = 0;
    for(int i = 0; arr[i]; ++i) {
        res *= 10;
        res += arr[i] - '0';

    }
    return res;
}

int conv(int num, int l, int r) {
    // l과 r 체크
    char buf[16];
    sprintf(buf, "%d", num);
    char tmp;
    tmp = buf[l];
    buf[l] = buf[r];
    buf[r] = tmp;
    // 앞자리 0이 아닌지 체크
    return tonum(buf);
}

int n, k;

int main() {
    // todo - 완전탐색
    scanf("%d%d", &n, &k);
    /*
        예외는 바로 처리 1 ~ 9 -> -1 / 10 .. 90 -> -1 / 등
    */
    queue<int> q;
    q.push(n);
    for(int i = 0; i < k; ++i) {
        int sz = q.size();
        for(int j = 0; j < sz; ++j) {
            int num = q.front();
            q.pop();
            // 교환 진행
            // (0.1), (0,2) ...(n-2, n-1)
        }
    }
}