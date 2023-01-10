#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int n, P;
vector<vector<int> > costs;
bool states[16];

int bitCount(int n) {
    if(n == 0) return 0;
    return (n%2) + bitCount(n/2);
}

int solve() {

}

int main() {
    cin >> n;
    costs.assign(n, vector<int>(n, 0));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> costs[i][j];
        }
    }
    string now;
    cin >> now;
    for(int i = 0; i < n; ++i) {
        if(now[i] == 'Y') states[i] = 1;
        else states[i] = 0; 
    }
    cin >> P;
    cout << solve() << "\n";
}