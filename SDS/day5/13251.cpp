#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef long long ll;

int n;
vector<int> v;
int k;

double calc(int v, int t) {
    double ret = 1.0;
    for(int i = 0; i < k; ++i) {
        ret *= (double)(v--) / (t--);
    }
    return ret;
}

int main() {
    scanf("%d", &n); v.assign(n, 0);
    int total = 0;
    for(int i = 0; i < n; ++i) {
        scanf("%d", &v[i]);
        total += v[i];
    }
    scanf("%d", &k);

    if(k > 50) {
        cout << 0.0 << "\n";
        return 0;
    }

    double ret = 0.0;
    for(int i = 0; i < n; ++i) {
        if(k > v[i]) continue;
        ret += calc(v[i], total);
    }
    printf("%.9f\n", ret);
}