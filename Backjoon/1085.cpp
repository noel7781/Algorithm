#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int x, y, w, h;
    cin >> x >> y >> w >> h;
    int ret = min(min(min(abs(x), abs(y)), abs(w-x)),abs(h-y));
    cout << ret << "\n";
}
