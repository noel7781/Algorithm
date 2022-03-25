#include <bits/stdc++.h>
using namespace std;
int N;
int sz;
vector<int> sqs;
int cache[50001][301];
void get_sq() {
    int k = 1;
    while(k*k <= N) {
        sqs.push_back(k*k);
        k++;
    }
}
int solve(int left, int pos) {
    if(left < 0 || pos >= sz) return 1e9;
    if(left == 0) {
        return 0;
    }
    int& ret = cache[left][pos];
    if(ret != -1) return ret;
    ret = 1e9;
    ret = min(ret, solve(left, pos+1));
    ret = min(ret, 1+solve(left-sqs[pos], pos));
    return ret;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(cache, -1, sizeof(cache));
    cin >> N;
    get_sq();
    sz = sqs.size();
    cout << solve(N, 0) << "\n";
}