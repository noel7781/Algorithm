#include <iostream>

using namespace std;

void solve(int n) {
    if(n == 1) return;
    int t = n;
    while(t > 1) {
        bool is_found = false;
        for(int i = 2; i *i <= t; ++i) {
            if(t % i == 0) {
                is_found = true;
                cout << i << "\n";
                t /= i;
                break;
            }
        }
        if(!is_found) break;
    }
    cout << t << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    solve(n);
}