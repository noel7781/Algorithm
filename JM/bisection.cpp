#include <iostream>

using namespace std;

double f(double x);

double bisection(double lo, double hi) {
    if(f(lo) > 0)
        swap(lo, hi);
    while(fabs(hi - lo) > 2e-7) {
        double mid = (lo + hi) / 2;
        double fmid = f(mid);
        if(fmid <= 0)
           lo = mid;
        else
            hi = mid;
    }
    return (lo + hi) / 2;
}
int main() {
}
