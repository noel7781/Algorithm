#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

string s1, s2;
int cache[1001][1001];

int solve(int l, int r) {
    if(l < 0 || r < 0) return 0;
    int& ret = cache[l][r];
    if(ret != -1) return ret;
    if(s1[l] == s2[r]) ret = 1 + solve(l-1, r-1);
    else {
        ret = max(solve(l-1, r), solve(l, r-1));
    }
    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));
    cin >> s1 >> s2;
    cout << solve(s1.length()-1, s2.length()-1) << "\n";
}
