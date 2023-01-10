#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int N;
int use_counts[100001];
int counts = 0;
struct Info {
    int start;
    int end;
    bool operator<(const Info& o) const {
        if(start == o.start) {
            return end < o.end;
        }
        return start < o.start;
    }
};
vector<Info> Infos;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    Infos.resize(N);
    for(int i = 0; i < N; i++) {
        cin >> Infos[i].start >> Infos[i].end;
    }
    sort(Infos.begin(), Infos.end());
    priority_queue<int, vector<int>, greater<int> > orders;
    for(int i = 1; i <= N; i++) orders.push(i);
    priority_queue<pii, vector<pii>, greater<pii> > ends;
    for(int i = 0; i < N; i++) {
        int cur_time = Infos[i].start;
        while(!ends.empty() && ends.top().first <= cur_time) {
            int order = ends.top().second; ends.pop();
            orders.push(order);
        }
        int top = orders.top(); orders.pop();
        if(!use_counts[top]) counts++;
        use_counts[top]++;
        ends.push({Infos[i].end, top});
    }
    cout << counts << "\n";
    for(int i = 1; i <= N; i++) {
        if(use_counts[i]) cout << use_counts[i] << " ";
        else break;
    }
    cout << "\n";
}