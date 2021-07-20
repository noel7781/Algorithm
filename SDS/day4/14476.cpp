#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> v;
vector<int> left_gcd;
vector<int> right_gcd;

int gcd(int a, int b) {
    if(a < b) swap(a, b);
    if(a == b || b == 0) return a;
    return gcd(a%b, b);
}

int main() {
    cin >> n;
    v.assign(n+2, 1);
    for(int i = 1; i <= n; ++i) {
        cin >> v[i];
    }
    left_gcd.assign(n+2, 0);
    right_gcd.assign(n+2, 0);
    int ret = -1;
    int out = 0;
    for(int i = 1; i <= n; ++i) {
        left_gcd[i] = gcd(v[i], left_gcd[i-1]);
    }
    for(int i = n; i > 0; --i) {
        right_gcd[i] = gcd(v[i], right_gcd[i+1]);
    }
    for(int i = 1; i <= n; ++i) {
        int cur_gcd = gcd(left_gcd[i-1], right_gcd[i+1]);
        if(v[i] % cur_gcd == 0) continue;
        if(ret < cur_gcd) {
            ret = cur_gcd;
            out = v[i];
        }
    }
    if(ret == -1) {
        cout << ret << "\n";
    } else {
        cout << ret << " " << out << "\n";
    }

}