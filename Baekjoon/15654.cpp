#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int N, M;
int arr[10];
int fac(int n) {
    if(n <= 1) return 1;
    return n*fac(n-1);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+N);
    int f = fac(N-M);
    int turn = 0;
    do {
        if(turn % f != 0) {
            turn++;
            continue;
        }
        for(int i = 0; i < M; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        turn++;
    } while(next_permutation(arr, arr+N));
}
