#include <bits/stdc++.h>
using namespace std;
vector<string> V(5);
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for(int i = 0; i < 5; i++) cin >> V[i];
    for(int i = 0; i < 15; i++) {
        for(int j = 0; j < 5; j++) {
            if(i < V[j].length()) {
                cout << V[j][i];
            }
        }
    }
    cout << "\n";
    return 0;
}