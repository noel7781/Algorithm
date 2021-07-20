#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    if(a < b) swap(a, b);
    if(a == b || b == 0) return a;
    return gcd(a % b, b);
}

void solve(string& str) {
    bool infinity = false;
    if(str.find('(') != string::npos) {
        infinity = true;
    }
    str = str.substr(2);

    if(infinity) {
        int left_p_pos = 0;
        for(int i = 0; i < str.size(); ++i) {
            if(str[i] == '(') left_p_pos = i;
        }
        int right_p_pos = str.size() - 1;
        string u_s = (str.substr(0, left_p_pos) + str.substr(left_p_pos+1, right_p_pos - left_p_pos - 1));
        ll u = stoll(u_s);
        if(left_p_pos > 0) {
            u -= stoll(str.substr(0, left_p_pos));
        }
        string d_s = "";
        for(int i = 0; i < right_p_pos - left_p_pos - 1; ++i) {
            d_s += "9";
        }
        for(int i = 0; i < left_p_pos; ++i) {
            d_s += "0";
        }
        ll d = stoll(d_s);
        ll g = gcd(u, d);
        cout << u/g << "/" << d/g << "\n";
    } else {
        ll u = stoll(str);
        ll d = 1;
        for(int i = 0; i <str.length(); ++i) {
            d *= 10;
        }
        ll g = gcd(u, d);
        cout << u/g << "/" << d/g << "\n";
    }

}

int main() {
    int t; cin >> t;
    while(t--) {
        string str; cin >> str;
        solve(str);
    }
}