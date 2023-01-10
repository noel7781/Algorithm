#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

typedef pair<string, int> psi;

string src, dst; 

void padding_string(string& str) {
    while(str.size() != 4) {
        str = "0" + str;
    }
}

int D(int num) {
    num *= 2;
    num %= 10000;
    return num;
}
int S(int num) {
    if(num == 0) return 9999;
    return num-1;
}
int L(int num) {
    return (num * 10) % 10000 + num / 1000;
}
int R(int num) {
    return (num * 1000) % 10000 + num / 10;
}

string solve(string str) {
    int dist[10000];
    memset(dist, 0x3f, sizeof(dist));
    int num = stoi(str);
    int tar = stoi(dst);
    if(num == tar) return 0;
    queue<psi> q;
    q.push(psi("", num));
    while(!q.empty()) {
        string path = q.front().first; int count = q.front().first.size(); int now = q.front().second; q.pop();
        if(now == tar) return path;
        if(count > dist[now]) continue;
        int next = D(now);
        if(dist[(next)] > count+1) {
            dist[(next)] = count+1;
            q.push(psi(path+"D", next));
        }
        next = S(now);
        if(dist[(next)] > count+1) {
            dist[(next)] = count+1;
            q.push(psi(path+"S", next));
        }
        next = L(now);
        if(dist[(next)] > count+1) {
            dist[(next)] = count+1;
            q.push(psi(path+"L", next));
        }
        next = R(now);
        if(dist[(next)] > count+1) {
            dist[(next)] = count+1;
            q.push(psi(path+"R", next));
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--) {
        cin >> src >> dst;
        string ret = solve(src);
        cout << ret << "\n";
    }
}
