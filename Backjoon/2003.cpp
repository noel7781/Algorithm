#include <iostream>
#include <vector>

using namespace std;

int n, m;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    vector<int> v(n, 0);
    for(int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    int start = 0, end = 0;
    int sum = 0;
    int ret = 0;
    for(start = 0; start < n; ++start) {
        while(end < n && sum < m) {
            sum += v[end];
            end += 1;
        }
        if(sum == m) {
            ret += 1;
        }
        sum -= v[start];
    }
    cout << ret << "\n";
}
