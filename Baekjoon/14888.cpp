#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int N;
int ops[4];
int res_max = -1e9;
int res_min = 1e9;

void solve(vector<int>& v) {
    vector<int> copied;
    copied.resize(v.size());
    copy(v.begin(), v.end(), copied.begin());
    if(v.size() == 1) {
        if(v[0] > res_max) res_max = v[0];
        if(v[0] < res_min) res_min = v[0];
    } else {
        for(int i = 0; i < 4; ++i) {
            if(ops[i] == 0) continue;
            auto it = copied.begin();
            int t1 = *it;
            it = copied.erase(it);
            int t2 = *it;
            it = copied.erase(it);
            if(i == 0) copied.insert(it, t1+t2);
            if(i == 1) copied.insert(it, t1-t2);
            if(i == 2) copied.insert(it, t1*t2);
            if(i == 3) copied.insert(it, t1/t2);
            ops[i] -= 1;
            solve(copied);
            ops[i] += 1;
            copied.resize(v.size());
            copy(v.begin(), v.end(), copied.begin());
        }
    }
}


int main() {
    cin >> N;
    vector<int> v;
    v.resize(N);
    for(int i = 0; i < N; ++i) {
        cin >> v[i];
    }
    for(int i = 0; i < 4; ++i) {
        cin >> ops[i];
    }
    solve(v);
    cout << res_max << "\n" << res_min << "\n";
}