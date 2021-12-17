#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int main() {
    int N; cin >> N;
    vector<pii> v(N);
    for(int i = 0; i < N; i++) {
        int x; cin >> x;
        v[i] = pii(x, i+1);
    }
    sort(v.begin(), v.end());
    int sub = 0;
    for(auto num: v) {
        cout << num.first - num.second << "\n";
    }
    return 0;
}
