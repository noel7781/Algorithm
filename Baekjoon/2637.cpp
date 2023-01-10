#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int N, M;
vector<vector<pii> > infos;
bool basics[101];
int cache[101][101];
set<int> basic_components;

int solve(int compo, int basic_num) {
    if(compo == basic_num) return 1;
    if(infos[compo].size() == 0) return 0;
    if(basic_components.find(compo) != basic_components.end()) return 0;
    int& ret = cache[compo][basic_num];
    if(ret != -1) return ret;
    ret = 0;
    for(auto next: infos[compo]) {
        int compo_num = next.first, compo_count = next.second;
        ret += solve(compo_num, basic_num) * compo_count;
    }
    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    infos.resize(N+1);
    fill(basics, basics+100, 1);
    for(int i = 0; i < M; i++) {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        infos[n1].push_back(pii(n2, n3));
        basics[n1] = 0;
    }
    for(int i = 1; i <= N; i++) {
        if(basics[i]) basic_components.insert(i);
    }
    for(auto basic_component: basic_components) {
        cout << basic_component << " " << solve(N, basic_component) << "\n";
    }
    
}
