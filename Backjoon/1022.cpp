#include <bits/stdc++.h>

using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

int R1, C1, R2, C2;
int board[100][100];

int numlen(int x) {
    int ans = 0;
    while(x > 0) {
        ans += 1;
        x /= 10;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> R1 >> C1 >> R2 >> C2;
    int r1, r2, c1, c2;
    r1 = R1 + 5000;
    r2 = R2 + 5000;
    c1 = C1 + 5000;
    c2 = C2 + 5000;
    int step = 1;
    int num = 2;
    int y = 5000, x = 5000;
    if(r1 <= y && y <= r2 && c1 <= x && x <= c2) {
        board[y-r1][x-c1] = 1;
    }
    while(step <= 5000) {
        int y = 5000+step-1, x = 5000+step;
        if(r1 <= y && y <= r2 && c1 <= x && x <= c2) {
            board[y-r1][x-c1] = num;
        }
        while(y > 5000 - step) {
            if(r1 <= y && y <= r2 && c1 <= x && x <= c2) {
                board[y-r1][x-c1] = num;
            }
            num++;
            y--;
        }
        while(x > 5000 - step) {
            if(r1 <= y && y <= r2 && c1 <= x && x <= c2) {
                board[y-r1][x-c1] = num;
            }
            num++;
            x--;
        }
        while(y < 5000 + step) {
            if(r1 <= y && y <= r2 && c1 <= x && x <= c2) {
                board[y-r1][x-c1] = num;
            }
            num++;
            y++;
        }
        while(x <= 5000 + step) {
            if(r1 <= y && y <= r2 && c1 <= x && x <= c2) {
                board[y-r1][x-c1] = num;
            }
            num++;
            x++;
        }
        step += 1;
    }
    int maxNum = 0;
    for(int i = r1; i <= r2; i++) {
        for(int j = c1; j <= c2; j++) {
            maxNum = max(maxNum, board[i-r1][j-c1]);
        }
    }
    int maxLen = numlen(maxNum);
    for(int i = r1; i <= r2; i++) {
        for(int j = c1; j <= c2; j++) {
            string num = to_string(board[i-r1][j-c1]);
            num.insert(0, maxLen - num.length(), ' ');
            cout << num << " ";
        }
        cout << "\n";
    }
}
