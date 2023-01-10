#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> ips;
int N;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    ips.resize(N, vector<int>(32, 0));
    for(int i = 0; i < N; i++) {
        string str_ip; cin >> str_ip;
        stringstream ss(str_ip);
        string tmp;
        int pos = 0;
        while(getline(ss, tmp, '.')) {
            int num = stoi(tmp);
            for(int j = 0; j < 8; j++) {
                ips[i][8*(pos+1)-1-j] = num % 2;
                num /= 2;
            }
            pos++;
        }
    }
    bool is_done = false;
    vector<int> netm(32, 0);
    vector<int> one(4, 0);
    vector<int> ret(4, 0);
    for(int i = 0; i < 32; i++) {
        for(int j = 0; j < N; j++) {
            netm[i] += ips[j][i];
        }
        if(netm[i] == N || netm[i] == 0) {
            netm[i] = 1;
        } else {
            netm[i] = 0;
            break;
        }
    }
    for(int j = 0; j < 4; j++) {
        int ipone = 0;
        int mask = 0;
        for(int k = 8*j; k < 8*(j+1); k++) {
            ipone *= 2;
            ipone += ips[0][k];
            mask *= 2;
            mask += netm[k];
        }
        one[j] = ipone;
        ret[j] = mask;
    }
    cout << (one[0] & ret[0]) << "." << (one[1] & ret[1]) << "." << (one[2] & ret[2]) << "." << (one[3] & ret[3]) << "\n";
    cout << ret[0] << "." << ret[1] << "." << ret[2] << "." << ret[3] << "\n";
}