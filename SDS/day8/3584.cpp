#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n;
int l, r;
vector<vector<int> > graph;

int parent[16][10001];
int depth[10001];

void bfs(int src) {
	vector<bool> visit(n+1, 0);
	queue<int> q;
	q.push(src);
	visit[src] = 1;
	while(!q.empty()) {
		int now = q.front(); q.pop();
		for(auto next: graph[now]) {
			if(!visit[next]) {
				visit[next] = 1;
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
	for(int i = 0; diff; ++i) {
		if(diff % 2) l = parent[i][l];
		diff /= 2;
	}
	if(l == r) return l;
	else {
		for(int j = 15; j >= 0; --j) {
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
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
	freopen("test.txt", "r", stdin);
	int t; cin >> t;
	while(t--) {
		graph.clear();
		cin >> n;
		vector<bool> not_parent(n+1, 0);
		graph.assign(n+1, vector<int>());
		for(int i = 0; i < n-1; ++i) {
			int a, b; cin >> a >> b;
			graph[a].push_back(b);
			not_parent[b] = 1;
		}
		int src = 0;
		for(int i = 1; i <= n; ++i) {
			if(not_parent[i] == 0) {
				src = i;
				break;
			}
		}
		depth[src] = 0;
		bfs(src);
		for(int i = 1; i < 16; ++i) {
			for(int j = 1; j <= 10000; ++j) {
				parent[i][j] = parent[i-1][parent[i-1][j]];
			}
		}
		cin >> l >> r;
		cout << query(l, r) << "\n";
	}
}
