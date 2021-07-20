#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll N;
ll P, T;

int main() {
    cin >> N;
    cin >> P >> T;
    vector<ll> v;
    bool is_found = false;
    for(ll i = 1; i<= 2*N; ++i) {
        v.push_back(i);
    }
    for(ll i = 2*N - 1; i >= 2; --i) {
        v.push_back(i);
    }
    ll h1 = 0, h2 = 0;
    for(int i = 0; i < T; ++i) {
        h1 = h2 + 1;
        h2 += v[i % (4*N - 2)];
    }
    ll troll1 = 2*P - 1;
    ll troll2 = troll1 + 1;
    for(ll i = h1; i <= h2; ++i) {
        ll comp = i % (2*N);
        if(comp == 0)
            comp = 2*N;

        if(comp == troll1 || comp == troll2) {
            is_found = true;
            cout << "Dehet YeonJwaJe ^~^" << endl;
            break;
        }
    }
    if(!is_found) {
        cout << "Hing...NoJam" << endl;
    }
}