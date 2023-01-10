#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll K, N;
int main() {
    cin >> K >> N;
    if(N == 1) {
        cout << -1 << "\n";
    } else {
        cout << K*N/(N-1) + !!(K*N % (N-1))<< "\n";
    }
}