#include <iostream>
#include <vector>

using namespace std;

int n;

void fraction(int u, int d) {
    for(int i = 2; i <= min(u, d); ++i) {
        while(u % i == 0 && d % i == 0) {
            u /= i;
            d /= i;
        }
    }
    cout << u << "/" << d << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    vector<int> v(n);
    for(auto &it : v) cin >> it;
    for(int i = 1; i < n; ++i) {
        fraction(v[0], v[i]);
    }
    return 0;
}