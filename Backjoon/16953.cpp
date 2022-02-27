#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll A, B;
typedef pair<ll, int> pli;
int main() {
    cin >> A >> B;
    queue<pli> q;
    q.push({A, 1});
    int ret = -1;
    while(!q.empty()) {
        pli p = q.front(); q.pop();
        ll num = p.first; int count = p.second;
        if(num == B) {
            ret = count;
            break;
        }
        if(num*2 <= B) q.push({num*2, count+1});
        if(num*10+1 <= B) q.push({num*10+1, count+1});
    }
    cout << ret << "\n";
}