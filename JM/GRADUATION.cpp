#include <iostream>
#include <vector>
#include <cstring>

#define INF int(1e9)
using namespace std;

int N, K, L, M;
vector<int> preReq;
vector<int> sem;
int cache[11][(1 << 13) + 1];

int get(int n) {
    if(n == 1) return 0;
    return 1 + get(n/2);
}

int solve(int semesterNumber, int taken) {
    if(__builtin_popcount(taken) >= K) return 0;
    if(semesterNumber == M) return INF;
    int& ret= cache[semesterNumber][taken];
    if(ret != -1) return ret;
    ret = INF;
    for(int subset = sem[semesterNumber]; subset; subset = ((subset-1) & sem[semesterNumber])) {
        if(__builtin_popcount(subset) > L) continue;
        if(taken & subset) continue;
        int tmp = subset;
        bool find = true;
        while(tmp > 0) {
            int elem = tmp & (-tmp);
            int cnt = get(elem);
            if((preReq[cnt] & taken) == preReq[cnt]) {
                tmp &= (tmp - 1);
            } else {
                find = false;
                break;
            }
        }
        if(find) {
            ret = min(ret, 1 + solve(semesterNumber+1, taken | subset));
        }
    }
    /*
    int canTake = (sem[semesterNumber] & ~taken);
    for(int i = 0; i < N; ++i) {
        if((canTake & (1 << i)) && (taken & preReq[i]) != preReq[i]) {
            canTake &= ~(1 << i);
        }
    }
    for(int take = canTake; take > 0; take = ((take -1) & canTake)) {
        if(__builtin_popcount(take) > L) continue;
        ret = min(ret, 1 + solve(semesterNumber+1, taken | take));
    }
    */
    ret = min(ret, solve(semesterNumber+1, taken));
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--) {
        memset(cache, -1, sizeof(cache));
        preReq.clear(); sem.clear();
        cin >> N >> K >> M >> L;
        for(int i = 0; i < N; ++i) {
            int r_c; cin >> r_c;
            int sum = 0;
            for(int j = 0; j < r_c; ++j) {
                int t; cin >> t;
                sum |= (1 << t);
            }
            preReq.push_back(sum);
        }
        for(int i = 0; i < M; ++i) {
            int s_c; cin >> s_c;
            int sum = 0;
            for(int j = 0; j < s_c; ++j) {
                int t; cin >> t;
                sum |= (1 << t);
            }
            sem.push_back(sum);
        }
        int ret = solve(0, 0);
        if(ret >= INF) {
            cout << "IMPOSSIBLE\n";
        } else {
            cout << ret << "\n";
        }
    }
}
