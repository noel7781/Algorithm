#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

int dx[] = { 1, 0 };
int dy[] = { 0, 1 };

int ddy[] = { 0, 1, 0, -1 };
int ddx[] = { 1, 0, -1, 0 };

int is_visit[101][2][1 << 6];

int ans = 1e9;
int N, M;
int board[11][11];
int check_end = 0;
int island_count = 0;
vector<pii> islands;

bool inRange(int y, int x) {
	return y >= 0 && y < N && x >= 0 && x < M;
}

struct DisjointSet {
	vector<int> parent, rank;
	DisjointSet(int n) : parent(n + 1), rank(n + 1) {
		for (int i = 0; i <= n; i++) {
			parent[i] = i;
		}
	}
	int find(int u) {
		if (u == parent[u]) return u;
		return parent[u] = find(parent[u]);
	}
	bool merge(int u, int v) {
		u = find(u); v = find(v);
		if (u == v) return 0;
		if (rank[u] > rank[v]) swap(u, v);
		parent[u] = v;
		if (rank[u] == rank[v]) rank[v]++;
		return 1;
	}
};

void bfs(int y, int x, int& island_count) {
	queue<pii> q;
	int is_visit[11][11];
	memset(is_visit, 0, sizeof(is_visit));
	q.push({ y, x });
	is_visit[y][x] = 1;
	island_count += 1;
	board[y][x] = island_count;
	while (!q.empty()) {
		pii now = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int n_y = now.first + ddy[i], n_x = now.second + ddx[i];
			if (inRange(n_y, n_x) && !is_visit[n_y][n_x] && board[n_y][n_x] == -1) {
				is_visit[n_y][n_x] = 1;
				board[n_y][n_x] = island_count;
				q.push({ n_y, n_x });
			}
		}
	}
}


void solve(DisjointSet ds, int island_pos, int dir, int end, int merged, int acc) {
	if (merged == island_count-1) {
		if (ans > acc) {
			ans = acc;
			
		}
		return;
	}
	if (island_pos == end) {
		return;
	}

	int y = islands[island_pos].first, x = islands[island_pos].second;
	int next = 0;

	int put = 0;
	

	if (dir == 1)
		solve(ds, island_pos + 1, 0, end, merged, acc);
	else
		solve(ds, island_pos, 1, end, merged, acc);
	int n_y = y + dy[dir], n_x = x + dx[dir];
	if (!inRange(n_y, n_x)) {
		return;
	}
	for (;;) {
		if (!inRange(n_y, n_x)) break;
		if (board[n_y][n_x] > 0 && board[n_y][n_x] <= island_count) {
			if (put >= 2) {
                if (ds.merge(board[n_y][n_x], board[y][x])) {
					
					if (dir == 1)
						solve(ds, island_pos + 1, 0, end, merged+1, acc + put);
					else
						solve(ds, island_pos, 1, end, merged+1, acc + put);
				}
			}
			break;
		} else  {
			put++;
			board[n_y][n_x] += 10;
		}
		n_y += dy[dir], n_x += dx[dir];
	}
	n_y = y + dy[dir], n_x = x + dx[dir];
	for (;;) {
		if (!inRange(n_y, n_x)) break;
		if (board[n_y][n_x] > 0 && board[n_y][n_x] <= island_count) {
			break;
		} else if (board[n_y][n_x] > 0) {
			board[n_y][n_x] -= 10;
		}
		n_y += dy[dir], n_x += dx[dir];
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			board[i][j] *= -1;
		}
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] == -1) {
				bfs(i, j, island_count);
			}
		}
	}


	check_end = (1 << island_count) - 1;

	int ret = 1e9;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] > 0) {
				islands.push_back({ i, j });
			}
		}
	}

	DisjointSet ds(island_count);

	solve(ds, 0, 0, islands.size(), 0, 0);

	cout << (ans == 1e9 ? -1 : ans) << "\n";


}

