#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int N;
vector<pii> org;
vector<int> orders;
int board[2000001];
struct Info {
    int time;
    int left;
    int right;
};
int get_index(int key) {
    return lower_bound(orders.begin(), orders.end(), key) - orders.begin();
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    org.resize(N);
    orders.resize(2*N);
    for(int i = 0; i < N; i++) {
        cin >> org[i].first >> org[i].second;
        orders[i*2] = org[i].first;
        orders[i*2+1] = org[i].second;
    }
    sort(orders.begin(), orders.end());
    orders.erase(unique(orders.begin(), orders.end()), orders.end());
    for(int i = 0; i < N; i++) {
        int left = get_index(org[i].first), right = get_index(org[i].second);
        board[left]++;
        board[right]--;
    }
    int cur = 0;
    Info ret = {0, 0, 0};
    for(int i = 0; i <= 2000000; i++) {
        cur += board[i];
        if(cur > ret.time) {
            ret.time = cur;
            ret.left = i; ret.right = i;
        } else if(cur == ret.time) {
            if(ret.right == i-1) {
                ret.right = i;
            }
        }
    }
    cout << ret.time << "\n";
    cout << orders[ret.left] << " " << orders[ret.right+1] << "\n";
}