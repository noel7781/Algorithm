#include <bits/stdc++.h>

#define INF 10000

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

int H, W, N, M;
int eungi_hashs[2001];
int col_hashs[2001][2001];
int teacher_hashs[2001][2001];
int teacher_hashs2[2001][2001];

int row_hash1 = 997;
int row_hash2 = 811;
int col_hash = 463;

void rabin_karp(string& s, int line) {
	int col = s.length();
	int pow = 1;
	int ret = 0;
	for (int i = col - 1; i >= 0; i--) {
		ret += (s[i] * pow);
		pow *= col_hash;
	}
	eungi_hashs[line] = ret;
}

void rabin_karp_teacher(string& s, int W, int line) {
	int col = s.length();
	int pow = 1;
	int ret = 0;
	for (int i = 0; i + W <= col; i++) {
		if (i == 0) {
			for (int j = W - 1; j >= 0; j--) {
				ret += (s[j] * pow);
				if (j != 0) pow *= col_hash;
			}
		}
		else {
			ret -= (s[i - 1] * pow);
			ret *= col_hash;
			ret += s[i + W - 1];
		}
		col_hashs[line][i] = ret;
	}
}

void rabin_karp_row(int teacher_hashs[][2001], int H, int W, int N, int M,
	int row_hash) {
	for (int i = 0; i + W <= M; i++) {
		int ret = 0, pow = 1;
		for (int k = 0; k + H <= N; k++) {
			if (k == 0) {
				for (int s = H - 1; s >= 0; s--) {
					ret += col_hashs[s][i] * pow;
					if (s != 0) pow *= row_hash;
				}
			}
			else {
				ret -= col_hashs[k - 1][i] * pow;
				ret *= row_hash;
				ret += col_hashs[k + H - 1][i];
			}
			teacher_hashs[k][i] = ret;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	memset(teacher_hashs, 0, sizeof(teacher_hashs));
	memset(teacher_hashs2, 0, sizeof(teacher_hashs));
	cin >> H >> W >> N >> M;
	int target = 0;
	int target2 = 0;
	for (int i = 0; i < H; i++) {
		string s;
		cin >> s;
		rabin_karp(s, i);
	}
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		rabin_karp_teacher(s, W, i);
	}
	int pow = 1, pow2 = 1;
	for (int i = H - 1; i >= 0; i--) {
		target += eungi_hashs[i] * pow;
		pow *= row_hash1;
		target2 += eungi_hashs[i] * pow2;
		pow2 *= row_hash2;
	}
	rabin_karp_row(teacher_hashs, H, W, N, M, row_hash1);
	rabin_karp_row(teacher_hashs2, H, W, N, M, row_hash2);
	int ans = 0;
	for (int i = 0; i + H <= N; i++) {
		for (int j = 0; j + W <= M; j++) {
			if (teacher_hashs[i][j] == target &&
				teacher_hashs2[i][j] == target2)
				ans++;
		}
	}
	cout << ans << "\n";
}

