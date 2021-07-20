#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n, m;

ll getResult(vector<vector<int> >& v, int wall_idx1, int wall_idx2, vector<bool>& isEven, bool is2odd) {
    ll ret = 0;
    if(!is2odd) {
        for(int i = 0; i < n; ++i) {
            if(i == wall_idx1 || i == wall_idx2) {
                if(isEven[i]) {
                    ret += (ll)(v[i][0] + v[i][1]);
                } else {
                    ret += (ll)(2*v[i][0] + v[i][1]);
                }
            } else {
                if(isEven[i]) {
                    ret += (ll)(v[i][0] + v[i][1] + v[i][2] + v[i][3]);
                } else {
                    ret += (ll)(2*v[i][0] + v[i][1] + v[i][2] + v[i][3]);
                }
            }
        }
    } else {
        for(int i = 0; i < n; ++i) {
            if(i == wall_idx1 || i == wall_idx2) {
                if(isEven[i]) {
                    ret += (ll)(v[i][0] + v[i][1]);
                } else {
                    ret += (ll)(2*v[i][0] + v[i][1]);
                }
            } else {
                if(isEven[i]) {
                    ret += (ll)(2*v[i][0] + 2*v[i][1] + v[i][2] + v[i][3]);
                } else {
                    ret += (ll)(2*v[i][0] + v[i][1] + v[i][2] + v[i][3]);
                }
            }
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t_num; cin >> t_num;
    for(int test_case = 1; test_case <= t_num; ++test_case) {
        ll ret = 0;
        cin >> n >> m;
        vector<vector<int> > v(n);
        vector<bool> isEven(n, 0);
        priority_queue<pii> even_pq;
        priority_queue<pii> odd_pq;
        for(int i = 0; i < n; ++i) {
            int sz; cin >> sz;
            priority_queue<int, vector<int>, greater<int> > pq;
            for(int j = 0; j < sz; ++j) {
                int nn; cin >> nn;
                pq.push(nn);
            }
            sz = (sz % 2) ? 5 : 4;
            for(int kk = 0; kk < sz; ++kk) {
                v[i].push_back(pq.top());
                pq.pop();
            }
            if(sz == 4) {
                even_pq.push(pii(v[i][2] + v[i][3], i));
                isEven[i] = 1;
            } else {
                odd_pq.push(pii(v[i][2] + v[i][3], i));
            }
        }
        // 짝수인지 홀수인지, 짝수면 p3 + p4, 홀수면 q3 + q4가 최소
        // 짝수만 있는경우
        if(odd_pq.size() == 0) {
            pii top1 = even_pq.top(); even_pq.pop();
            pii top2 = even_pq.top(); even_pq.pop();
            for(int i = 0; i < n; ++i) {
                if(i == top1.second || i == top2.second) {
                    ret += (ll)(v[i][0] + v[i][1]);
                } else {
                    ret += (ll)(v[i][0] + v[i][1] + v[i][2] + v[i][3]);
                }
            }
        }
        // 홀수만 있는 경우
        else if(even_pq.size() == 0) {
            pii top1 = odd_pq.top(); odd_pq.pop();
            pii top2 = odd_pq.top(); odd_pq.pop();
            for(int i = 0; i < n; ++i) {
                if(i == top1.second || i == top2.second) {
                    ret += (ll)(2*v[i][0] + v[i][1]);
                } else {
                    ret += (ll)(2*v[i][0] + v[i][1] + v[i][2] + v[i][3]);
                }
            }

        }
        // 다있는경우
        else {
            pii top1 = even_pq.top(); even_pq.pop();
            pii top2 = even_pq.top(); even_pq.pop();
            pii top3 = odd_pq.top(); odd_pq.pop();
            pii top4 = odd_pq.top(); odd_pq.pop();
            int t1idx = top1.second, t2idx = top2.second, t3idx = top3.second, t4idx = top4.second;
            int t1val = top1.first, t2val = top2.first, t3val = top3.first, t4val = top4.first;
            bool is2Odd = false; if(odd_pq.empty()) is2Odd = true;
            ret = (ll)1<<60;
            ret = min(ret, getResult(v, t1idx, t2idx, isEven, 0));
            ret = min(ret, getResult(v, t1idx, t3idx, isEven, 0));
            ret = min(ret, getResult(v, t1idx, t4idx, isEven, 0));
            ret = min(ret, getResult(v, t2idx, t3idx, isEven, 0));
            ret = min(ret, getResult(v, t2idx, t4idx, isEven, 0));
            ret = min(ret, getResult(v, t3idx, t4idx, isEven, is2Odd));
        }
        cout << "Case #" << test_case << "\n";
        cout << ret << "\n";
    }
}
