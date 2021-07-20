#include <iostream>
#include <vector>

using namespace std;

int n, target;
vector<int> arr;

int main() {
    cin >> n >> target;
    arr.assign(n+1, 0);
    for(int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    /*
    vector<int> sum;
    for(int i = 1; i <= n; ++i) {
        sum[i] = sum[i-1] + arr[i];
    }
    int s = 1, e = n;
    */
    int sum = 0;
    int s = 1, e= 1;
    int ret = 1e9;
    bool is_found = false;
    while(s <= n) {
        while(sum < target) {
            if(e > n) break;
            sum += arr[e++];
        }
        if(sum >= target) {
            ret = min(ret, e-s);
            // cout << "e"<< e<<" and s : " << s << endl;
            is_found = true;
        }
        sum -= arr[s++];
    }
    if(!is_found) {
        cout << 0 << "\n";
    } else {
        cout << ret << "\n";
    }
}
