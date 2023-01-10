#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int N, M;
int arr[10];
int fac(int n) {
    if(n <= 1) return 1;
    return n*fac(n-1);
}
void solve(vector<int>& save) {
    if(save.size() == M) {
        for(auto it: save) {
            cout << it << " ";
        }
        cout << "\n";
        return;
    }
    for(int i = 0; i < N; i++) {
        save.push_back(arr[i]);
        solve(save);
        save.pop_back();
    }
    return;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+N);
    vector<int> save;
    solve(save);
}
