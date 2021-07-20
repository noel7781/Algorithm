#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n; scanf("%d", &n);
    double ret1 = n * n * M_PI;
    double ret2 = (double)n * n * 2;
    printf("%.7f\n", ret1);
    printf("%.7f\n", ret2);

}
