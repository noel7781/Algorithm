#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

bool decision(vector<double>& loc, int size, int cam, double gap) {
    int count = 0;
    double pos = -gap;
    for(int i = 0; i < size; ++i) {
        if(loc[i] - pos >= gap) {
            pos = loc[i];
            count += 1;
        }
    }
    if(count >= cam) return true;
    return false;
}

double solve(vector<double>& loc, int size, int cam) {
    double lo = 0, hi = 241;
    for(int i = 0; i < 100; ++i) {
        double mid = (lo + hi) / 2;
        if(decision(loc, size, cam, mid)) {
            lo = mid;
        } else {
            hi = mid;
        }
    }
    return lo;
}

int main() {
    int t; scanf("%d", &t);
    while(t--) {
        int n, m; scanf("%d %d", &n, &m);
        vector<double> loc(m);
        for(int i = 0; i < m; ++i) {
            scanf("%lf", &loc[i]);
        }
        printf("%.2f\n", solve(loc, m, n));
    }
}
