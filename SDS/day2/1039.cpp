#include <cstdio>
#include <vector>
#include <queue> 
using namespace std;

int tonum(char arr[]) {
    int res = 0;
    for (int i = 0 ; arr[i] ; i++) {
        res *= 10;
        res += arr[i] - '0';
    }
    return res;
}

int conv(int num, int l, int r) {
    char buf[16];
    sprintf(buf, "%d", num);
    char tmp;
    tmp = buf[l];
    buf[l] = buf[r];
    buf[r] = tmp;
    // 앞자리가 0이 아닌지 체크도.. 
    if(buf[0] == '0') return 0;
    return tonum(buf);
}

int n, k;

bool isOk(int num) {
    if(num < 10) return false;
    if(num < 100 && num % 10 == 0) return false;
    return true;
}

int get_num_len(int num) {
    int len = 0;
    while(num > 0) {
        len++;
        num /= 10;
    }
    return len;
}

int main() {
    scanf("%d%d", &n, &k);
    if(!isOk(n)) {
        printf("-1");
        return 0;
    }
    queue<int> q;
    q.push(n);
    for (int i = 0 ; i < k ; i++) {
        vector<int> next_q;
        bool visit[1000001] = {false, };
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            int len = get_num_len(cur);
            for(int s = 0; s < len; s++) {
                for(int e = s+1; e < len; e++) {
                    int next_num = conv(cur, s, e);
                    if(next_num == 0) continue;
                    if(!visit[next_num]) {
                        visit[next_num] = 1;
                        next_q.push_back(next_num);
                    }
                }
            }
        }
        for(int i = 0; i < next_q.size(); i++) {
            q.push(next_q[i]);
        }
    }
    // k번을 돌렸기 때문에 q에남아 있는 것들은 k번을 수행하고 남은 숫자들이고
    // q에 남은것 중에 가장 큰것을 출력하면 됨 
    int ans = 0;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        if(ans < cur) ans = cur;
    }
    printf("%d\n", ans);
}