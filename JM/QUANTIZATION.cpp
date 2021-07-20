#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int t;
int n, s;
int cache[101][11];
vector<int> v;

int pSum[101], pSqSum[101];

void precalc() {
    pSum[0] = v[0];
    pSqSum[0] = v[0] * v[0];
    for(int i = 1; i < n; ++i) {
        pSum[i] = pSum[i-1] + v[i];
        pSqSum[i] = pSqSum[i-1] + v[i]*v[i];
    }
}

int minError(int from, int end) {
    int size = end - from + 1;
    int sum = 0;
    for(int i = from; i <= end; ++i) {
        sum += v[i];
    }
    int mean = (int)((double)sum / size + 0.5);
    sum = 0;
    for(int i = from; i <= end; ++i) {
        sum += (v[i] - mean) * (v[i] - mean);
    }
    return sum;
}

int quantize(int from, int parts) {
    if(from == n)
        return 0;
    if(parts == 0)
        return 1e9;
    int& ret = cache[from][parts];
    if(ret != -1)
        return ret;
    ret = 1e9;
    for(int size = 1; from+size <= n; ++size) {
        ret = min(ret, minError(from, from + size - 1) + quantize(from + size, parts - 1));
    }
    return ret;
}

int main() {
    cin >> t;
    while(t--) {
        memset(cache, -1, sizeof(cache));
        memset(pSum, 0, sizeof(pSum));
        memset(pSqSum, 0, sizeof(pSqSum));
        v.clear();
        cin >> n >> s;
        v.assign(n, 0);
        for(int i = 0; i < n; ++i) {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        cout << quantize(0, s) << "\n";
    }
}
