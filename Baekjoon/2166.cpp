#include <iostream>
#include <vector>

using namespace std;

typedef pair<double, double> pdd;

double get_area(pdd A, pdd B, pdd C) {
    double ret = (A.first*B.second + B.first*C.second + C.first*A.second - 
               (A.second*B.first + B.second*C.first + C.second*A.first));
    return ret * 0.5;
}

int main() {
    int n; scanf("%d", &n);
    vector<pdd> p;
    for(int i = 0; i < n; ++i) {
        double a, b; scanf("%lf %lf", &a, &b);
        p.push_back(pdd(a, b));
    }
    pdd org = p[0];
    double ret = 0;
    for(int i = 0; i < n-2; ++i) {
        ret += get_area(p[0], p[i+1], p[i+2]);
    }
    printf("%.1lf", abs(ret));
}
