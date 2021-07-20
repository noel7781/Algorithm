#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int cache[101][101][101];

int solve(int a, int b, int c) {

    int& ret = cache[a+50][b+50][c+50];
    if(ret != -1) return ret;
    ret = 0;
    if(a <= 0 || b <= 0 || c <= 0) return ret = 1;
    if(a > 20 || b > 20 || c > 20) return ret = solve(20, 20, 20);
    if(a < b && b < c) return ret = solve(a, b, c-1) + solve(a, b-1, c-1) - solve(a, b-1, c);

    return ret = solve(a-1, b, c) + solve(a-1, b-1, c) + solve(a-1, b, c-1) - solve(a-1, b-1, c-1);

}

int main() {
    memset(cache, -1, sizeof(cache));
    int a = 0, b = 0, c = 0;
    while(1) {
        scanf("%d %d %d", &a, &b, &c);
        if(a == -1 && b == -1 && c == -1) {
            break;
        }
        printf("w(%d, %d, %d) = %d\n", a, b, c, solve(a, b, c));
    }
    return 0;
}
