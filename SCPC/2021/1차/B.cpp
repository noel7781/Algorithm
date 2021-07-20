#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int n, t;
char A[50001];
char B[50001];
bool check[50001];

void solve() {
    for(int i = 0; i < n; ++i) {
        if(B[i] == '1' && !check[i]) {
            if(i < t) {
                check[i] = 1;
                if(i+2*t < n) check[i+2*t] = 1;
                A[i+t] = '1';
            } else {
                if(i+2*t < n && B[i+2*t] == '1') {
                    check[i+2*t] = 1;
                    A[i+t] = '1';
                } else if(i+2*t < n && B[i+2*t] == '0') {
                    A[i-t] = '1';
                } else if(i+2*t >= n) {
                    if(i+t >= n) {
                        A[i-t] = '1';
                    } else {
                        A[i+t] = '1';
                    }
                }
            }
        }
    }
    // for(int i = n-1; i >= 0; --i) {
    //     if(B[i] == '1' && !check[i]) {
    //         if(i - 2*t >= 0 && B[i-2*t] == '1') {
    //             check[i] = true;
    //             check[i-2*t] = true;
    //             A[i-t] = '1';
    //         } else {
    //             if(i + 2*t >= n) {
    //                 if(i + t < n) {
    //                     A[i+t] = '1';
    //                 } else {
    //                     A[i-t] = '1';
    //                 }
    //             } else if(i + 2*t < n && B[i+2*t] == '1')  {
    //                 A[i+t] = '1';
    //             }
    //             else {
    //                 A[i-t] = '1';
    //             }
    //             check[i] = true;
    //         }
    //     }
    // }
}

int main() {
    int t_num; scanf("%d", &t_num);
    for(int test_case = 1; test_case <= t_num; ++test_case) {
        memset(check, 0, sizeof(check));
        memset(A, 0, sizeof(A));
        memset(B, 0, sizeof(A));
        scanf("%d%d", &n, &t);
        for(int i = 0; i < n; ++i) {
            scanf(" %c", &B[i]);
            A[i] = '0';
        }
        solve();
        printf("Case #%d\n", test_case);
        printf("%s\n", A);
    }
}
