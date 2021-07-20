#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

typedef pair<int, int> pii;

const int MAX_N = 10000001;

int n, lo, hi;
pii factor[MAX_N];

void eratosthenes() {
    factor[0].first = factor[1].first = -1;
    factor[0].second = factor[1].second = 1;
    for(int i = 2; i <= MAX_N; ++i) {
        factor[i] = make_pair(i, 2);
    }
    int sqrtn = int(sqrt(MAX_N));
    for(int i = 0; i <= sqrtn; ++i) {
        if(factor[i].first == i) {
            for(int j = i*i; j <= MAX_N; j += i) {
                if(factor[j].first == j) {
                    factor[j].first = i;
                }
            }
        }
    }
    for(int i = 0; i < MAX_N; ++i) {
        int minFactor = factor[i].first;
        if(factor[i].first != i) factor[i].second = factor[i / minFactor].second + 1;
    }
}

int main() {
    eratosthenes();
    int t; cin >> t;
    for(int i = 2; i <= 500; ++i) {
        printf("i: %d minFactor: %d cnt %d\n", i, factor[i].first, factor[i].second);
    }
    while(t--) {
        int ret = 0;
        cin >> n >> lo >> hi;
        for(int x = lo; x <= hi; ++x) {
            if(factor[x].second == n)
                ret += 1;
        } 
        cout << ret << "\n";
    }
}
