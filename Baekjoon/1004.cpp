#include <ios>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int x1, y1, x2, y2;
int n;

bool isInside(int X, int Y, int R, int x, int y) {
    if((X-x)*(X-x) + (Y-y)*(Y-y) > R*R) return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--) {
        cin >> x1 >> y1 >> x2 >> y2;
        int ret = 0;
        cin >> n;
        for(int i = 0; i < n; ++i) {
            int X, Y, R; cin >> X >> Y >> R;
            bool left = isInside(X, Y, R, x1, y1);
            bool right = isInside(X, Y, R, x2, y2);
            if((left && !right) || (!left && right)) ret++;
        }
        cout << ret << "\n";
    }
}
