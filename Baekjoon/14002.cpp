#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n;
int cache[1005];
int now[1005];
vector<int> v;

int solve(int pos) {
    int& ret = cache[pos];
    if(ret != -1) return ret;
    ret = 0;
    for(int i = pos+1; i <= n; ++i) {
        if(v[i] > v[pos]) {
            int length = 1 + solve(i);
            if(length > ret) {
                ret = length;
                now[pos] = i;
            }
        }
    }
    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));
    memset(now, -1, sizeof(now));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    v.resize(n+1);
    for(int i = 1; i <= n; ++i) {
        cin >> v[i];
    }
    cout << solve(0) << "\n";
    int path = now[0];
    while(path != -1) {
        cout << v[path] << " ";
        path = now[path];
    }

}