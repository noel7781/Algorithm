#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int K;
vector<int> A, B;
vector<int> A_to_idx, B_to_idx;
vector<int> check;
bool calc_dist(int x, int y) {
    int a_dist = 0, b_dist = 0;
    int p1 = A_to_idx[x], p2 = A_to_idx[y];
    for(a_dist = 2; ; a_dist <<= 1) {
        if((p1 / a_dist) == (p2 / a_dist)) break;
    }
    p1 = B_to_idx[x], p2 = B_to_idx[y];
    for(b_dist = 2; ; b_dist <<= 1) {
        if((p1 / b_dist) == (p2 / b_dist)) break;
    }
    return a_dist == b_dist;
}

set<pii> solve(int left, int right) {
    if(left == right) {
        set<pii> ret;
        ret.insert({-1, A[left]});
        return ret;
    }
    set<pii> ret;
    // -count, first
    int mid = (left + right) >> 1;
    set<pii> v_l = solve(left, mid);
    set<pii> v_r = solve(mid+1, right);
    for(auto l_it = v_l.begin(); l_it != v_l.end(); l_it++) {
        for(auto r_it = v_r.begin(); r_it != v_r.end(); r_it++) {
            int l_cnt = -l_it->first, l_first = l_it->second;
            int r_cnt = -r_it->first, r_first = r_it->second;
            if(calc_dist(l_first, r_first)) {
                int min_v = min(l_first, r_first);
                if(check[min_v] <= l_cnt+r_cnt) {
                    check[min_v] = l_cnt+r_cnt;
                    ret.insert({-(l_cnt+r_cnt), min_v});
                }
            } else {
                if(l_cnt >= r_cnt) {
                    if(check[l_first] <= l_cnt) {
                        check[l_first] = l_cnt;
                        ret.insert({-l_cnt, l_first});
                    }
                }
                if(l_cnt <= r_cnt) {
                    if(check[r_first] <= r_cnt) {
                        check[r_first] = r_cnt;
                        ret.insert({-r_cnt, r_first});
                    }
                }
            }
        }
    }
    for(auto l_it = v_l.begin(); l_it != v_l.end(); l_it++) {
        int l_cnt = -l_it->first, l_first = l_it->second;
        for(int j = mid+1; j <= right; j++) {
            if(calc_dist(l_first, A[j])) {
                int min_v = min(A[j], l_first);
                if(check[min_v] <= l_cnt+1) {
                    ret.insert({-(l_cnt+1), min_v});
                    check[min_v] = l_cnt+1;
                }
            }

        }
    }
    for(auto r_it = v_r.begin(); r_it != v_r.end(); r_it++) {
        int r_cnt = -r_it->first, r_first = r_it->second;
        for(int i = left; i <= mid; i++) {
            if(calc_dist(A[i], r_first)) {
                int min_v = min(A[i], r_first);
                if(check[min_v] <= r_cnt+1) {
                    ret.insert({-(r_cnt+1), min(A[i], r_first)});
                    check[min_v] = r_cnt+1;
                }
            }
        }
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> K;
    int N = pow(2, K-1);
    A.resize(N); B.resize(N);
    A_to_idx.resize(N); B_to_idx.resize(N);
    check.resize(N);
    int index = 0;
    for(auto &it: A) {
        cin >> it;
        it--;
        A_to_idx[it] = index++;
    }
    index = 0;
    for(auto &it: B) {
        cin >> it;
        it--;
        B_to_idx[it] = index++;
    }
    set<pii> ret = solve(0, N-1);
    cout << -ret.begin()->first << "\n";
}