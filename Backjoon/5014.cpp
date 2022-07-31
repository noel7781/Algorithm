#include <bits/stdc++.h>
using namespace std;
int F, S, G, U, D;
int cache[1000001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(cache, 0x3f, sizeof(cache));
    cin >> F >> S >> G >> U >> D;
    queue<int> q;
    q.push(S);
    cache[S] = 0;
    while(!q.empty()) {
        auto pos = q.front(); q.pop();
        if(pos == G) {
            cout << cache[pos] << "\n";
            return 0;
        }
        if(pos+U <= F && cache[pos+U] > cache[pos]+1) {
            cache[pos+U]= cache[pos]+1;
            q.push(pos+U);
        }
        if(pos-D >= 1 && cache[pos-D] > cache[pos]+1) {
            cache[pos-D]= cache[pos]+1;
            q.push(pos-D);
        }
    }
    cout << "use the stairs\n";
    return 0;
}