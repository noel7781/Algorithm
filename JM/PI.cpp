#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int t;
int cache[10001];

int solve(string& s, int pos) {
    int len = s.length();
    if(pos >= len)
        return 0;
    int& ret = cache[pos];
    if(ret != -1)
        return ret;
    ret = 1e9;

    // 1
    if(s[pos] == s[pos+1]) {
        int count = 0;
        for(int i = 0; i < 4 && pos+i < len; ++i) {
            if(s[pos+i] == s[pos+i+1]) {
                count += 1;
            } else {
                break;
            }
        }
        while(count >= 2) {
            ret = min(ret, 1+solve(s, pos+count+1));
            count -= 1;
        }
    }
    // 2
    int diff = s[pos] - s[pos+1];
    if(diff == 1 || diff == -1) {
        int count = 0;
        for(int i = 0; i < 4 && pos+i < len; ++i) {
            if(diff == s[pos+i]-s[pos+i+1]) {
                count += 1;
            } else {
                break;
            }
        }
        while(count >= 2) {
            ret = min(ret, 2+solve(s, pos+count+1));
            count -= 1;
        }
    }
    // 4
    if(s[pos] == s[pos+2]) {
        ret = min(ret, 4+solve(s, pos+3));
        if(pos+3 < len && s[pos+1] == s[pos+3]) {
            ret = min(ret, 4+solve(s, pos+4));
            if(pos+4 < len && s[pos] == s[pos+4]) {
                ret = min(ret, 4+solve(s, pos+5));
            }
        }

    }
    // 5
    if(!(diff == 1 || diff == -1)) {
        int count = 0;
        for(int i = 0; i < 4 && pos+i < len; ++i) {
            if(diff == s[pos+i]-s[pos+i+1]) {
                count += 1;
            } else {
                break;
            }
        }
        while(count >= 2) {
            ret = min(ret, 5+solve(s, pos+count+1));
            count -= 1;
        }
    }
    // 10
    ret = min(ret, min(10+solve(s, pos+3), min(10 + solve(s, pos+4), 10 + solve(s, pos+5))));


    return ret;
}

int main() {
    cin >> t;
    while(t--) {
        memset(cache, -1, sizeof(cache));
        string s; cin >> s;
        cout << solve(s, 0) << "\n";
    }
}
