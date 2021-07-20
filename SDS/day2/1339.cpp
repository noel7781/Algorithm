#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int alpha[30];
vector<string> v;

int main() {
    cin >> n;
    v.assign(n, "");
    for(int i = 0; i < n; ++i) {
        cin >> v[i];
        int k = 1;
        for(int j = v[i].size() - 1; j >= 0; --j) {
            alpha[v[i][j] - 'A'] += k;
            k *= 10;
        }
    }
    sort(alpha, alpha+30, greater<int>());
    int ret = 0;
    for(int i = 0; i < 10; ++i) {
        ret += alpha[i] * (9-i);
    }
    cout << ret << "\n";
}