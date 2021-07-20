#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int t;
int n, m, k;

const int M = 1000000000+100;
int bino[201][201];

void calcBino() {
    memset(bino, 0, sizeof(bino));
    for(int i = 0; i <= 200; ++i) {
        bino[i][0] = bino[i][i] = 1;
        for(int j = 1; j < i; ++j) {
            bino[i][j] = min(M, bino[i-1][j-1] + bino[i-1][j]);
        }
    }
}

void generate(int n, int m, string s) {
    if(k < 0) return;
    if(n==0 && m==0) {
        if(k == 0)
            cout << s << endl;
        k -= 1;
        return;
    }
    if(bino[n+m][n] <= skip) {
        skip -= bino[n+m][n];
        return;
    }
    if(n > 0) generate(n-1, m, s+"-");
    if(m > 0) generate(n, m-1, s+"o");
}

strint kth(int n, int m, int skip) {
    if(n==0) return string(m, 'o');
    if(skip < bino[n+m-1][n-1])
        return "-" + kth(n-1, m, skip);
    return "o" + kth(n, m-1, skip-bino[n+m-1][n-1]);
}

int main() {
    cin >> t;
    while(t--) {
        cin >> n >> m >> k;
        string signal;
        generate(n, m, signal);
    }
}
