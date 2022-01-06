#include <bits/stdc++.h>

using namespace std;

int N, M, H;


// [N][H]
int ladders[11][31];

int advance(int src, int h) {
    if(h == H+1) {
        return src;
    }
    if(ladders[src][h] == 1) {
        return advance(src+1, h+1);
    } else if(ladders[src-1][h] == 1) {
        return advance(src-1, h+1);
    } else {
        return advance(src, h+1);
    }
}

bool match(int add) {
    if(add == 0) {
        for(int n = 1; n <= N; n++) {
            if(advance(n, 1) != n) return false;
        }
        return true;
    }
    bool ret = false;
    for(int n = 1; n <= N; n++) {
        for(int h = 1; h <= H; h++) {
            if(ladders[n-1][h] == 1) continue;
            if(ladders[n][h] == 1) continue;
            ladders[n][h] = 1;
            ret = ret | match(add-1);
            if(ret) return ret;
            ladders[n][h] = 0;
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> H;
    for(int i = 0; i < M; i++) {
        int A, B; cin >> A >> B;
        ladders[B][A] = 1;
    }
    
    for(int add = 0; add <= 3; ++add) {
        if(match(add)) {
            cout << add << "\n";
            return 0;
        }
    }
    cout << -1 << "\n";
    return 0;
}
