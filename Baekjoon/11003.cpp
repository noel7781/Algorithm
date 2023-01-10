#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int n, l;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> l;
    v.assign(n, 0);
    for(int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    deque<int> dq;
    for(int i = 0; i < n; ++i) {
        if(dq.empty()) {
            dq.push_back(i);
            cout << v[dq.front()] << " ";
        } else {
            if(dq.front()+l <= i) {
                dq.pop_front();
            }
            bool erase = false;
            while(!dq.empty() && v[dq.back()] > v[i]) {
                dq.pop_back();
            }
            dq.push_back(i);

            cout << v[dq.front()] << " ";
        }
    }
}
