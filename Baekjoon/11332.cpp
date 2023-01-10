#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
vector<string> cases = { "O(N)", "O(N^2)", "O(N^3)", "O(2^N)", "O(N!)"};
int main() {
    int t; cin >> t;
    while(t--) {
        string s; ll N, T, L;
        ll limit = (ll)1e8;
        cin >> s >> N >> T >> L;
        bool is_tle = false;
        if(s == cases[0]) {
            if(limit*L < N*T) is_tle = true; 
        } else if(s == cases[1]) {
            if(limit*L < N*N*T) is_tle = true;
        } else if(s == cases[2]) {
            if(limit*L < N*N*T) is_tle = true;
            else if(limit*L < N*N*N*T) is_tle = true;
        } else if(s == cases[3]) {
            ll n = 1;
            ll acc = 1;
            while(n <= N) {
                acc <<= 1;
                if(limit*L < acc*T) {
                    is_tle = true;
                    break;
                }
                n += 1;
            }

        } else if(s == cases[4]) {
            ll n = 1;
            ll acc = 1;
            while(n <= N) {
                acc *= n;
                if(limit*L < acc*T) {
                    is_tle = true;
                    break;
                }
                n += 1;
            }
        }
        if(is_tle) {
            cout << "TLE!\n";
        } else {
            cout << "May Pass.\n";
        }

    }
}
