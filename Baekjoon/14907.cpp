#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > adj;
int ins[26];
int outs[26];
int costs[26];

int solve() {
    queue<int> q;
    int distances[26] = {0, };
    for(int i = 0; i < 26; i++) {
        if(ins[i] == 0) {
            q.push(i);
            distances[i] = costs[i];
        }
    }
    while(!q.empty()) {
        int now = q.front(); q.pop();
        for(auto next: adj[now]) {
            ins[next]--;
            if(ins[next] == 0) q.push(next);
            distances[next] = max(distances[next], distances[now] + costs[next]);
        }
    }
    int ans = 0;
    for(int i = 0; i < 26; i++) {
        ans = max(ans, distances[i]);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    adj.resize(26);
    while(cin) {
        string str;
        getline(cin, str);
        if(str.empty()) break;
        int p1 = str.find(" ");
        string src = str.substr(0, p1);
        str.erase(0, p1+1);
        int p2 = str.find(" ");
        string cost;
        if(p2 == -1) {
            cost = str;
            costs[src[0]-'A'] = stoi(cost);
            continue;
        } else {
            cost = str.substr(0, p2);
            costs[src[0]-'A'] = stoi(cost);
        }
        str.erase(0, p2+1);
        string dst = str;
        for(auto next: str) {
            int idx = next - 'A';
            ins[src[0]-'A']++;
            outs[idx]++;
            adj[idx].push_back(src[0]-'A');
        }
    }
    cout << solve() << "\n";
}