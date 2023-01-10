#include <bits/stdc++.h>
using namespace std;
struct Ant {
    int pos;
    int dir;
    int idx;
    bool operator<(const Ant &rhs) const {
        return pos < rhs.pos;
    }
};
int N, L;
void move_ants(vector<Ant>& ants, int time) {
    for(int i = 0; i < N; i++) {
        if(ants[i].pos == 0 || ants[i].pos == L) continue;
        ants[i].pos += (time * ants[i].dir);
    }
    for(int i = 0; i < N-1; i++) {
        if(ants[i].pos == 0 || ants[i].pos == L) continue;
        if(ants[i].pos == ants[i+1].pos || ants[i].pos == ants[i+1].pos+1) {
            swap(ants[i], ants[i+1]);
        }
    }
}
int main() {
    cin >> N >> L;
    vector<Ant> ants(N);
    for(int i = 0; i < N; i++) {
        int x; cin >> x;
        if(x > 0) {
            ants[i].pos = x; ants[i].dir = 1; ants[i].idx = i;
        } else {
            ants[i].pos = -x; ants[i].dir = -1; ants[i].idx = i;
        }
    }
    sort(ants.begin(), ants.end());
    int acc_time = 0;
    while(1) {
        int time = 1e9;
        int ant_count = 0;
        int ant_idx = -1;
        for(int i = 0; i < N; i++) {
            if(ants[i].pos == 0 || ants[i].pos == L) continue;
            ant_count++;
            ant_idx = ants[i].idx;
            if(i < N-1) {
                if(ants[i].dir * ants[i+1].dir < 0) {
                    time = min(time, (ants[i+1].pos - ants[i].pos + 1) / 2);
                }
            }
            if(i == 0) {
                if(ants[i].dir == -1) {
                    time = min(time, ants[i].pos);
                }
            }
            if(i == N-1) {
                if(ants[i].dir == 1) {
                    time = min(time, L - ants[i].pos);
                }
            }
        }
        acc_time += time;
        if(ant_count == 1) {
            cout << ant_idx+1 << " " << acc_time << endl;
            return 0;
        }
        cout << "ANT STATUS:\n";
        for(auto it: ants) {
            cout << it.pos << " ";
        }
        cout << "\n";
        move_ants(ants, time);
    }
}