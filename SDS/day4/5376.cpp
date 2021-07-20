#include <iostream>
#include <cstring>

using namespace std;

int getGCD(int a, int b) {
    if(a < b) swap(a, b);
    if(a == b || b == 0) return a;
    return getGCD(a%b, b);
}

int main() {
    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        if(s.find('(') == string::npos) {
            // 없는 경우
            string next = s.substr(2);
            int length = next.length();
            string down = "1";
            while(length > 0) {
                down += "0";
                length -= 1;
            }
            int up_i = stoi(next);
            int down_i = stoi(down);
            int gcd = getGCD(up_i, down_i);
            printf("%d/%d\n", up_i/gcd, down_i/gcd);
        } else {
            string next = s.substr(2);
            int p_start = next.find('(');
            string downs = next.substr(0, p_start);
            string rep = next.substr(p_start+1);
            rep.pop_back();
            string down = "9";
            int rep_len = rep.length();
            while(rep_len > 1) {
                rep_len -= 1;
                down += "9";
            }
            int down_len = downs.length();
            while(down_len > 0) {
                down += "0";
                down_len -= 1;
            }
            for(auto it = next.begin(); it != next.end();) {
                if(*it == '(' || *it == ')') {
                    it = next.erase(it);
                } else {
                    it++;
                }
            }
            int up_i = stoi(next);
            if(downs.length() > 0) up_i -= stoi(downs);
            int down_i = stoi(down);
            int gcd = getGCD(up_i, down_i);
            printf("%d/%d\n", up_i/gcd, down_i/gcd);
        }
    }
}