#include <bits/stdc++.h>
using namespace std;
int N;
int M;
bool buttons[10];
int dists[1000001];
void search(int x) {
    if(x == 0) return;
    for(int i = 0; i < 10; i++) {
        if(buttons[i] && 10*x+i <= 1000000) {
            if(x != 100) dists[10*x+i] = min(dists[10*x+i], dists[x] + 1);
            else dists[10*x+i] = min(dists[10*x+i], 4);
            search(10*x+i);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M; memset(buttons, 1, sizeof(buttons)); 
    for(int i = 0; i <= 1000000; i++) dists[i] = 1e9;
    for(int i = 0; i < M; i++) { int x; cin >> x; buttons[x] = 0; }
    dists[100] = 0;
    for(int j = 0; j < 10; j++) {
        if(buttons[j]) {
            dists[j] = 1;
            search(j);
        }
    }
    int ret = 1e9;
    for(int j = 0; j <= 1000000; j++) {
        dists[j] = dists[j] + abs(N-j);
        ret = min(ret, dists[j]);
    }
    cout << ret << "\n";
}