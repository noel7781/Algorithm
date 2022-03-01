#include <bits/stdc++.h>
using namespace std;
int N;
vector<int> V;
int cache[1001][501][501];
bool is_done = false;

int search(int pos, int sum, int take) {
    if(take == 0) {
        if(sum == 0) return 1;
        else return 0;
    }
    if(pos >= 2*N) return 0;
    int& ret = cache[pos][sum][take];
    if(ret != -1) return ret;
    ret = 0;
    ret |= search(pos+1, sum, take);
    ret |= search(pos+1, (sum+V[pos]) % N, take-1);
    return ret;
}

void reconstruct(int pos, int sum, int take, vector<int>& path) {
    if(is_done) return;
    if(take == 0) {
        if(sum == 0) {
            for(auto it: path) cout << it << " ";
            cout << "\n";
            is_done = true;
            return;
        }
        return;
    }
    if(search(pos,sum,take) == search(pos+1,(sum+V[pos]) % N,take-1)) {
        path.push_back(V[pos]);
        reconstruct(pos+1, (sum+V[pos]) % N, take-1, path);
        path.pop_back();
        if(is_done) return;
    } else {
        reconstruct(pos+1, sum, take, path);
        if(is_done) return;
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(cache, -1, sizeof(cache));
    cin >> N;
    V.resize(2*N-1);
    for(auto &it: V) cin >> it;
    int ret = search(0, 0, N);
    if(ret) {
        vector<int> path;
        reconstruct(0, 0, N, path);
    } else {
        cout << -1 << "\n";
    }
    return 0;
}