#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

unsigned long long int Combination(int a, int b);

int cache[31][31];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(cache, -1, sizeof(cache));
    int count = 0;
    int M = 0, N = 0;
    vector<int> a, b;
    cin >> count;
    for (int i = 0; i < count; i++) {
        cin >> M >> N;
        a.push_back(M);
        b.push_back(N);
    }
    for (int i = 0; i < count; i++) {
        cout << Combination(b[i], a[i]) << endl;
    }
    return 0;
}

unsigned long long int Combination(int a, int b) {
    if (b == 1) {
        return a;
    } else if (a == b) {
        return 1;
    } else {
        int& ret = cache[a][b];
        if(ret != -1) return ret;
        return ret = Combination(a - 1, b) + Combination(a - 1, b - 1);
    }
}
