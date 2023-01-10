#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int N;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    vector<int> v[2];

    ll sum = 0;
    ll T = 1;
    if(N != 1) {
        int rest = (2*N*(2*N+1))/2;
        v[0].push_back(2*N);
        for(int i = 0; i < N-2; ++i) {
            v[0].push_back(i+1);
        }
        v[0].push_back(2*N-1);
        for(int i = 2*N - 3; i >= N-1; --i) {
            v[1].push_back(i);
        }
        v[1].push_back(2*N-2);

        for(int i = 0; i < N; ++i) {
            rest -= v[1][i];
            sum += T * rest;
            T += 1;
        }
        for(int j = N-1; j >= 0; --j) {
            rest -= v[0][j];
            sum += T * rest;
            T += 1;
        }
        cout << sum << "\n";
        for(auto x: v[0]) {
            cout << x << " ";
        }
        cout << endl;
        for(auto x: v[1]) {
            cout << x << " ";
        }
        cout << endl;
    } else {
        cout << 2 << "\n";
        cout << 1 << "\n";
        cout << 2 << "\n";
    }
}