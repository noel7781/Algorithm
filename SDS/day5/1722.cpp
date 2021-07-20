#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef long long ll;

ll fac[21];
bool check[21];

int n;
void getFactorial() {
    fac[0] = 1;
    fac[1] = 1;
    for(ll i = 2; i <= 20; ++i) {
        fac[i] = fac[i-1] * i;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    getFactorial();
    cin >> n;
    vector<int> v;
    for(int i = 1; i <= n; ++i) {
        v.push_back(i);
    }
    int q; cin >> q;
    if(q == 1) {
        ll k; cin >> k;
        vector<int> ret;
        int count = n;
        bool done = false;
        int i = 1;
        while(count > 0) {
            ll size = fac[count-1];
            while(check[i]) i++;
            while(k > size) {
                k -= size;
                while(check[++i])
                continue;
            }
            ret.push_back(i);
            check[i] = 1;
            i = 1;
            count--;
            if(k == 1) {
                for(i; i <= n; ++i) {
                    if(!check[i]) ret.push_back(i);
                }
                done = true;
                break;
            }
            if(done) break;
        }
        for(auto it: ret) {
            cout << it << " ";
        }
        cout << "\n";
    } else {
        vector<int> target(n, 0);
        for(auto &it: target) cin >> it;
        ll ret = 1;
        for(int i = 0; i < n; ++i) {
            ll count = 0;
            for(int j = 1; j <= n; ++j) {
                if(!check[j] && j < target[i]) count++;
                else if(j == target[i]) {
                    check[j] = true;
                    break;
                }
            }
            ret += count * fac[n-i-1];
        }
        cout << ret << "\n";
    } 
}