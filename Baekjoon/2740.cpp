#include <iostream>

using namespace std;

int N, M, K;
int A[101][101];
int B[101][101];

void solve() {
    for(int p = 0; p < N; ++p) {
        for(int q = 0; q < K; ++q) {
            int sum = 0;
            for(int r = 0; r < M; ++r) {
                sum += A[p][r] * B[r][q];
            }
            cout << sum << " ";
        }
        cout << endl;
    }
}

int main() {
    cin >> N >> M;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            cin >> A[i][j];
        }
    }
    cin >> M >> K;
    for(int i = 0; i < M; ++i) {
        for(int j = 0; j < K; ++j) {
            cin >> B[i][j];
        }
    }
    solve();
}