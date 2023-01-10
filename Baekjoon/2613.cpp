#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n, m;
vector<int> v;
int p_sum[301];
int cache[301][301];
vector<int> save;

int solve(int pos, int k, int limit) {
    int sum = 0;
    int cnt = 0;
    for(int i = 0; i < n; ++i) {
        if(v[i] > limit) return false;
        if(sum + v[i] > limit) {
            cnt += 1;
            sum = v[i];
        } else {
            sum += v[i];
        }
    }
    cnt += 1;
    //cout<<"limit: " <<limit << " and count: "<< cnt << endl;
    if(k >= cnt) {
        return true;
    }

    return false;
}

int findRight(int limit, int contain, int pos) {
    if(contain == m && pos == n) {
        for(auto &it: save) {
            cout << it << " ";
        }
        cout << "\n";
        return 1;
    }
    int& ret = cache[contain][pos];
    if(ret != -1) return ret;
    ret = 0;
    int sum = 0;
    for(int i = pos; i < n; ++i) {
        if(sum + v[i] <= limit) {
            sum += v[i];
            save.push_back(i-pos+1);
            //cout<<"pos: "<< pos << " and sum: " << sum << endl;
            if(ret == 1) return ret;
            ret = max(ret, findRight(limit, contain+1, i+1));
            save.pop_back();
        } else {
            break;
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(cache, -1, sizeof(cache));
    cin >> n >> m;
    v.assign(n, 0);
    for(int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    int lo = 0, hi =30000;
    while(lo+1 < hi) {
        int mid = (lo + hi) / 2;
        if(solve(0, m, mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    cout << hi << endl;
    findRight(hi, 0, 0);
}
