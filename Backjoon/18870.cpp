#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<int> v(n, 0);
    int index = 0;
    for(auto &it: v) {
        cin >> it;
    }
    map<int, int> m;
    priority_queue<int, vector<int>, greater<int> > pq;
    int before = -1e9 - 1;
    for(auto it : v) {
        pq.push(it);
    }
    int value = 0;
    while(!pq.empty()) {
        int next = pq.top();
        pq.pop();
        if(m.find(next) == m.end()) {
            m[next] = value++;
        }
    }
    for(auto it: v) {
        cout << m[it] << " ";
    }
}
