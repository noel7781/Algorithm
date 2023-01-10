#include <iostream>
#include <map>

using namespace std;

int t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t--) {
        int n; cin >> n;
        map<string, int> m;
        for(int i = 0; i < n; ++i) {
            string a, b;
            cin >> a >> b;
            m[b]++;
        }
        int ret = 1;
        for(auto it : m) {
            ret *= (it.second+1);
        }
        cout << ret-1 << "\n";
    }
}