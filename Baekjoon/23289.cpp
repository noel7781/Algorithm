#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;

struct fan_info {
	int x;
	int y;
	int d;
};

int R, C, K, W;
int board[21][21];
int walls[45][45];
int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };
int ddx[4][3] = { {-1, 0, 1}, {-1, 0, 1},  {-1, -1, -1}, {1, 1, 1} };
int ddy[4][3] = { {1, 1, 1}, {-1, -1, -1}, {-1, 0, 1}, {-1, 0, 1} };
vector<fan_info> vf;
vector<pair<int, int> > check_rooms;

bool inRange(int x, int y) {
	return 0 <= x && x < R && 0 <= y && y < C;
}

void copy_board(int board[][21], int next_board[][21]) {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			next_board[i][j] = board[i][j];
		}
	}
	return;
}

void blow() {
	bool is_visit[21][21];
	for (auto fan : vf) {
		int fan_x = fan.x, fan_y = fan.y, fan_dir = fan.d - 1;
		int power = 5;
		queue<tuple<int, int, int> > q;
		q.push({ fan_x + dx[fan_dir], fan_y + dy[fan_dir], power });
		memset(is_visit, 0, sizeof(is_visit));
		is_visit[fan_x + dx[fan_dir]][fan_y + dy[fan_dir]] = 1;
		int x, y, p;
		while (!q.empty()) {
			tie(x, y, p) = q.front(); q.pop();
			if (!inRange(x, y)) continue;
			board[x][y] += p;
			for (int t = 0; t < 3; t++) {
				int next_x = x + ddx[fan_dir][t], next_y = y + ddy[fan_dir][t];
				if (!inRange(next_x, next_y)) continue;
				int tmp_d = fan_dir / 2;
				if (tmp_d == 0 && (walls[x + next_x][2 * y] || walls[next_x * 2][y + next_y])) continue;
				if (tmp_d == 1 && (walls[2 * x][y + next_y] || walls[x + next_x][2 * next_y])) continue;
				if (is_visit[next_x][next_y]) continue;
				is_visit[next_x][next_y] = 1;
				if(p > 1) q.push({ next_x, next_y, p-1 });
			}

		}
	}
}

void adjust_temperature() {
	int next_board[21][21];
	memset(next_board, 0, sizeof(next_board));
	copy_board(board, next_board);


	queue<pair<int, int> > q;
	q.push({ 0, 0 });
	int next_x = -1, next_y = -1;
	int is_visit[21][21];
	memset(is_visit, 0, sizeof(is_visit));
	is_visit[0][0] = 1;
	while (!q.empty()) {
		pair<int, int> now = q.front(); q.pop();
		
		// 가로
		next_x = now.first, next_y = now.second + 1;
		if (inRange(next_x, next_y)) {
			int diff = abs(board[now.first][now.second] - board[next_x][next_y]) / 4;
			if (board[next_x][next_y] > board[now.first][now.second]) diff *= -1;
			if (!walls[now.first + next_x][now.second + next_y]) {
				next_board[now.first][now.second] -= diff;
				next_board[next_x][next_y] += diff;
			}
			if (!is_visit[next_x][next_y]) {
				is_visit[next_x][next_y] = 1;
				q.push({ next_x, next_y });
			}
		}
		// 세로
		next_x = now.first + 1, next_y = now.second;
		if (inRange(next_x, next_y)) {
			int diff = abs(board[now.first][now.second] - board[next_x][next_y]) / 4;
			if (board[next_x][next_y] > board[now.first][now.second]) diff *= -1;
			if (!walls[now.first + next_x][now.second + next_y]) {
				next_board[now.first][now.second] -= diff;
				next_board[next_x][next_y] += diff;
			}
			if (!is_visit[next_x][next_y]) {
				is_visit[next_x][next_y] = 1;
				q.push({ next_x, next_y });
			}
		}
	}

	copy_board(next_board, board);
}

void external_adjust() {
	for (int j = 0; j < C; j++) {
		if (board[0][j]) board[0][j]--;
		if (board[R-1][j]) board[R-1][j]--;
	}
	for (int i = 1; i < R - 1; i++) {
		if (board[i][0]) board[i][0]--;
		if (board[i][C - 1]) board[i][C - 1]--;
	}
}

bool check_temperature_K() {
	for (auto room : check_rooms) {
		if (board[room.first][room.second] < K) return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> R >> C >> K;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			int sp; cin >> sp;
			if (sp != 0 && sp < 5) {
				vf.push_back({ i, j, sp });
			}
			else if (sp == 5) {
				check_rooms.push_back({ i, j });
			}
			board[i][j] = 0;
		}
	}
	cin >> W;
	for (int i = 0; i < W; i++) {
		int x, y, t; cin >> x >> y >> t;
		x -= 1; y -= 1;
		if (t == 0) {
			walls[2 * x - 1][2 * y] = 1;
		}
		else {	
			walls[2 * x][2 * y + 1] = 1;
		}
	}
	int choco = 0;
	while (choco <= 100) {
		blow();
		adjust_temperature();
		external_adjust();		
		choco++;
		if (check_temperature_K()) break;
	}
	cout << choco << "\n";
}