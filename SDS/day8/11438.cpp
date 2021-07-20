#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int depth[100001];
int parent[21][100001];
int n, m;
vector<vector<int> > g;

void bfs(int src) {
	queue<int> q;
	q.push(src);
	vector<bool> visit(n+1, 0);
	visit[src] = true;
	while(!q.empty()) {
		int now = q.front(); q.pop();
		for(int next: g[now]) {
			if(!visit[next]) {
				visit[next] = true;
				q.push(next);
				depth[next] = depth[now] + 1;
				parent[0][next] = now;
			}
		}
	}
	return;
}

int query(int l, int r) {

	if(depth[l] < depth[r]) swap(l, r);
	int diff = depth[l] - depth[r];
	int cnt = 0;
	while(diff > 0) {
		if(diff % 2) l = parent[cnt][l]; 
		diff /= 2;
		cnt++;
	}
	
	if(l == r) return l;

	else {
		for(int j = 19; j >= 0; --j) {
			if(parent[j][l] > 0 && parent[j][l] != parent[j][r]) {
				l = parent[j][l];
				r = parent[j][r];
			}
		}
		l = parent[0][l];
	}
	return l;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
//	freopen("test.in.txt", "r", stdin);
	cin >> n;
	g.assign(n+1, vector<int>());
	for(int i = 0; i < n-1; ++i) {
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	depth[1] = 0;
	bfs(1);
	
	for(int i = 1; i < 20; ++i) {
		for(int j = 0; j < 100001; ++j) {
			parent[i][j] = parent[i-1][parent[i-1][j]];
		}
	}

	cin >> m;
	while(m--) {
		int a, b; cin >> a >> b;
		cout << query(a, b) << "\n";
	}
	
}
