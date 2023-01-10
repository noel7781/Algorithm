#include <bits/stdc++.h>
using namespace std;
int N;
vector<int> V;
int search(vector<int>& orders, int taken) {
    if(taken == (1<<N)-1) {
        int ret = 0;
        for(int j = 0; j < N-1; j++) {
            ret += abs(V[orders[j]] - V[orders[j+1]]);
        }
        return ret;
    }
    int ret = 0;
    for(int i = 0; i < N; i++) {
        if(!(taken & (1 << i))) {
            orders.push_back(i);
            ret = max(ret, search(orders, taken | (1 << i)));
            orders.pop_back();
        }
    }
    return ret;
}
int main() {
    cin >> N; V.resize(N); for(auto &it: V) cin >> it;
    vector<int> orders;
    cout << search(orders, 0);
}