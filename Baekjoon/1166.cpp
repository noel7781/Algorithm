#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;
using ull=unsigned long long;

ull n;
ull l, w, h;

ull min(ull a, ull b, ull c) {
    return min(min(a,b),c);
}

int main() {
    cin >> n >> l >> w >> h;
    double start = 0;
    double end = 1e9;
    double mid = -1;
    for(int i = 0; i < 1000; ++i) {
        mid = (start + end) / 2;
        ull put = (ull)(l / mid) * (ull)(w / mid) * (ull)(h / mid);
        if(n <= put) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    //cout << setprecision(9) << mid << "\n";
    printf("%.9f\n", mid);
}

