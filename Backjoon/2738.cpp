#include <bits/stdc++.h>
using namespace std;
int arr[101][101];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N, M; cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }
    int x;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> x; cout << arr[i][j] + x << " ";
        }
        cout << "\n";
    }
}