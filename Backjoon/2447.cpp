#include <iostream>
#include <vector>

using namespace std;

void solve(vector<string>& v, int n, int y, int x) {
    if(n == 3) {
        for(int i = y; i < y+3; ++i) {
            for(int j = x; j < x+3; ++j) {
                v[i][j] = '*';
            }
        }
        v[y+1][x+1] = ' ';
        return;
    }
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            if(i == 1 && j == 1) continue;
            solve(v, n/3, y + n/3 * i, x + n/3 * j);
        }
    }
    return;
}

int main() {
    int n; cin >> n;
    vector<string> v(n, string(n, ' '));
    solve(v, n, 0, 0);
    for(int i = 0; i < v.size(); ++i) {
        for(int j = 0; j < v[i].size(); ++j) {
            cout << v[i][j];
        }
        cout << "\n";
    }
    return 0;
}
