#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int W, H, A;
int N, M;
int left_arr[100001];
int right_arr[100001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> W >> H >> A;
    N = W; M = H;
    memset(left_arr, -1, sizeof(left_arr));
    memset(right_arr, -1, sizeof(right_arr));
    int lcost = 1, rcost = 1;
    if(W <= 100000) left_arr[W] = 0;
    if(H <= 100000) right_arr[H] = 0;
    W = (W+1)/2;
    while(W > 100000) {
        lcost++;
        W = (W+1)/2;
    }
    int prev = min(100000, N-1);
    while(prev >= 1) {
        for(int j = W; j <= prev; j++) {
            left_arr[j] = lcost;
        }
        lcost++;
        prev = W-1;
        W = (W+1)/2;
    }

    H = (H+1)/2;
    while(H > 100000) {
        rcost++;
        H = (H+1)/2;
    }
    prev = min(100000, M-1);
    while(prev >= 1) {
        for(int j = H; j <= prev; j++) {
            right_arr[j] = rcost;
        }
        rcost++;
        prev = H-1;
        H = (H+1)/2;
    }
    
    int ret = 123456789;
    for(int k = 1; k <= A; k++) {
        if(k * (A/k) == A) {
            if(left_arr[k] == -1 || right_arr[A/k] == -1) continue;
            ret = min(ret, left_arr[k]+right_arr[A/k]);
        }
    }
    cout << (ret == 123456789 ? -1 : ret) << "\n";
}