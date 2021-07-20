#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    v.resize(N);
    for(int i = 0; i < N; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int ret = 0;
    int before = 0;
    for(int i = 0; i < N; ++i) {
        ret += v[i] + before;
        before += v[i];
    }
    cout << ret << "\n";
}