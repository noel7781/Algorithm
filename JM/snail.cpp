#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

int h, d; 
double cache[1001][2001];

double solve(int day, int climb) {
    if(day == d)
        return (climb >= h) ? 1.0 : 0.0;
    double& ret = cache[day][climb];
    if(ret != -1.0)
        return ret;
    return ret = solve(day + 1, climb + 1) * 0.25 + solve(day + 1, climb + 2) * 0.75;
}

int main() {
    int t_cnt; cin >> t_cnt;
    while(t_cnt--) {
        for(int i = 0; i < 1001; ++i) {
            for(int j = 0; j < 2001; ++j) {
                cache[i][j] = -1.0;
            }
        }
        scanf("%d %d", &h, &d);
        printf("%.9f\n", solve(0, 0));
    }
}
