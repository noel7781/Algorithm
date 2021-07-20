#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n, k;
vector<pii> jewelry;
vector<int> bag;
ll ret = 0;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    jewelry.resize(n, pii(0, 0));
    bag.resize(k, 0);
    for(int i = 0; i < n; ++i) {
        cin >> jewelry[i].first >> jewelry[i].second;
    }
    for(int i = 0; i < k; ++i) {
        cin >> bag[i];
    }
    sort(jewelry.begin(), jewelry.end());
    sort(bag.begin(), bag.end());
    int pos = 0;
    priority_queue<int> pq;
    for(int i = 0; i < k; ++i) {
        int cur_bag = bag[i];
        while(pos < n && jewelry[pos].first <= cur_bag) {
            pq.push(jewelry[pos].second);
            pos += 1;
        }
        if(pq.empty()) continue;
        ret += (ll)pq.top();
        pq.pop();
    }
    cout << ret << "\n";


}