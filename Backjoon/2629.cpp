#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int w[63];
int test[8];
int n; 
int cache[40003][63];

int check(int c, int pos) {
    if(pos == 2*n) {
        if(c == 0) return 1;
        return 0;
    }
    int& ret = cache[c][pos];
    if(ret != -1) return ret;
    ret = 0;
    ret = check(c, pos+1);
    if(c >= w[pos])
        ret = max(ret, check(c-w[pos], pos+1));
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(cache, -1, sizeof(cache));
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> w[n+i];
    }
    for(int i = 0; i < n; ++i) {
        w[i] = -w[2*n-i-1];
    }
    int t; cin >> t;
    while(t--) {
        int c; cin >> c;
        if(check(c, 0)) {
            cout << "Y ";
        } else {
            cout << "N ";
        }
    }
}
