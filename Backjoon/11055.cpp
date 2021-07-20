#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n;
int cache[1002];
int S[1001];

int lis(int start) {
    if(start == n)
        return 0;
    int& ret = cache[start+1];
    if(ret != -1)
        return ret;
    ret = 0;
    for(int next = start+1; next <= n; ++next) {
        if(start == -1) {
            ret = max(ret, lis(next));
        } else if(S[start] < S[next]) {
            ret = max(ret, S[start] + lis(next));
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(cache, -1, sizeof(cache));
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> S[i];
    }
    S[n] = 1e9;
    cout << lis(-1) << "\n";
}

