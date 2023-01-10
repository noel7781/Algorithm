#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int n;

void solve(vector<pii>& arr) {
    for(int i = 0; i < n; ++i) {
        int cnt = 1;
        for(int j = 0; j < n; ++j) {
            if(arr[i].first < arr[j].first && arr[i].second < arr[j].second) {
                cnt += 1;
            }
        }
        cout << cnt << " ";
    }
}

int main() {
    cin >> n;
    vector<pii> v(n);
    for(int i = 0; i < n; ++i) {
        cin >> v[i].first >> v[i].second;
    }
    solve(v);
}
