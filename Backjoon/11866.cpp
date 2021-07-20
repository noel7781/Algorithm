#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue<int> q;
    vector<int> ret;
    int n, k; cin >> n >> k;
    for(int i = 1; i <= n; ++i) {
        q.push(i);
    }
    while(!q.empty()) {
        for(int i = 0; i < k-1; ++i) {
            int x = q.front();
            q.pop();
            q.push(x);
        }
        int x = q.front();
        ret.push_back(x);
        q.pop();
    }
    cout << "<";
    for(int i = 0; i < n; ++i) {
        cout << ret[i];
        if(i != n-1) cout << ", ";
    }
    cout << ">";
}
