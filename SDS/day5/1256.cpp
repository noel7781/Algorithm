#include <iostream>
#include <vector>
#include <cstring>

#define INF 1000000010

using namespace std;

int n, m;
int k;
int cache[101][101];

int getCount(int a, int z) {
    if(a == 0 || z == 0) return 1;
    int& ret = cache[a][z];
    if(ret != -1) return ret;
    ret = getCount(a-1, z) + getCount(a, z-1);
    if(ret >= INF) {
        ret = INF;
    }
    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));
    cin >> n >> m >> k;
    if(getCount(n, m) < k) {
        cout << -1 << "\n";
        return 0;
    }
    int count_a = n, count_z = m;
    string ret = "";
    for(int i = 0; i < n+m; ++i) {
        if(count_a == 0 || count_z == 0) {
            for(int i = 0; i < count_a; ++i) {
                ret += "a";
            }
            for(int i = 0; i < count_z; ++i) {
                ret += "z";
            }
            break;
        }
        int comp = getCount(count_a-1, count_z);
        if(k <= comp) {
            ret += "a";
            count_a -= 1;
        } else {
            ret += "z";
            k -= comp;
            count_z -= 1;
        }
    }
    cout << ret << "\n";
    return 0;
}