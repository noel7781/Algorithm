#include <iostream>
#include <vector>
#include <map>
#include <cstring>

using namespace std;

int A[2001];
int B[2001];

map<int, int> mA;
map<int, int> mB;

int size;
int m, n;

void expand() {
    for(int i = 0; i < m-1; ++i) {
        A[m+i] = A[i];
    }
    for(int i = 0; i < n-1; ++i) {
        B[n+i] = B[i];
    }
}

void precalculate() {
    for(int i = 0; i < m; ++i) {
        int sum = 0;
        for(int j = 0; j < m; ++j) {
            sum += A[i+j];
            mA[sum] += 1;
        }
    }
    for(int i = 0; i < n; ++i) {
        int sum = 0;
        for(int j = 0; j < n; ++j) {
            sum += B[i+j];
            mB[sum] += 1;
        }
    }
    int aSum = 0;
    int bSum = 0;
    for(int i = 0; i < m; ++i) {
        aSum += A[i];
    }
    for(int i = 0; i < n; ++i) {
        bSum += B[i];
    }
    mA[aSum] = 1;
    mB[bSum] = 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> size;
    cin >> m >> n;
    for(int i = 0; i < m; ++i) {
        cin >> A[i];
    }
    for(int i = 0; i < n; ++i) {
        cin >> B[i];
    }
    expand();
    precalculate();

    int ret = 0;
    for(int i = 0; i <= size; ++i) {
        ret += (mA[i] * mB[size-i]);
    }
    ret += mA[size];
    ret += mB[size];
    cout << ret << "\n";
}
