#include <iostream>
#include <vector>
#include <cstring>
#include <tuple>
#include <map>
#include <algorithm>

using namespace std;

typedef long long ll;

int N;
vector<ll> V;
ll abs_min_sum = -1;
vector<int> ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ans.assign(3, 0);
    cin >> N;
    V.resize(N);
    for(auto &it: V) cin >> it;
    sort(V.begin(), V.end());
    for(int pivot = 0; pivot < N-2; pivot++) {
        int left = pivot+1; int right = N-1;
        while(left < right) {
            ll sum = V[pivot] + V[left] + V[right];
            if(abs(sum) < abs_min_sum || abs_min_sum == -1) {
                abs_min_sum = abs(sum);
                ans[0] = V[pivot];
                ans[1] = V[left];
                ans[2] = V[right];
            }
            if(sum < 0) left++;
            else right--;
        }
    }
    for(auto x: ans) cout << x << " ";
}
