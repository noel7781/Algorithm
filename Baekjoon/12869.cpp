#include <bits/stdc++.h>
using namespace std;
int N;
vector<int> Hps;
vector<int> cands = { 1, 3, 9 };
vector<vector<int> > subsets;
int dists[61][61][61];
struct myType {
    int cnts;
    vector<int> v;
    bool operator<(const myType& other) const {
        return this->cnts > other.cnts;
    }
};
void getSubset(vector<int>& tmp, int cur, int cnt) {
    if(cnt == 3) {
        subsets.push_back(tmp);
        return;
    }
    for(auto &num: cands) {
        if(cur & (1 << num)) continue;
        tmp.push_back(num);
        getSubset(tmp, cur | (1 << num), cnt+1);
        tmp.pop_back();
    }
    return;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N; Hps.resize(3); for(int i = 0; i < N; i++) cin >> Hps[i];
    vector<int> empty;
    getSubset(empty, 0, 0);
    memset(dists, 0x3f, sizeof(dists));
    dists[Hps[0]][Hps[1]][Hps[2]] = 0;
    priority_queue<myType> pq;
    pq.push(myType { 0, Hps });
    while(!pq.empty()) {
        auto pq_top = pq.top(); pq.pop();
        auto cur_cnt = pq_top.cnts;
        auto cur_vec = pq_top.v;
        if(!cur_vec[0] && !cur_vec[1] && !cur_vec[2]) {
            cout << cur_cnt << "\n";
            return 0;
        }
        if(dists[cur_vec[0]][cur_vec[1]][cur_vec[2]] < cur_cnt) continue;
        for(auto &ss: subsets) {
            int h1 = max(0, cur_vec[0] - ss[0]), h2 = max(0, cur_vec[1] - ss[1]), h3 = max(0, cur_vec[2] - ss[2]);
            if(dists[h1][h2][h3] > cur_cnt+1) {
                dists[h1][h2][h3] = cur_cnt+1;
                pq.push(myType { cur_cnt+1, vector<int> {h1, h2, h3}});
            }
        }
    }
    return 0;
}