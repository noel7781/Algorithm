#include <iostream>
#include <vector>
#include <stack>

using namespace std;

typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int total = 0;
    int N; cin >> N;
    stack<pii> S;
    while(N--) {
        int is_new, score, time;
        cin >> is_new;
        if(is_new) {
            cin >> score >> time;
            S.push(make_pair(score, time));
        }
        if(!S.empty()) {
            pii tmp = S.top();
            S.pop();
            tmp.second -= 1;
            if(tmp.second == 0) {
                total += tmp.first;
            } else {
                S.push(tmp);
            }
        }
    }
    cout << total << "\n";
}