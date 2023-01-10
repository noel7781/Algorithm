#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Info {
    int from;
    int to;
    int weight;
};

bool comp(struct Info& A, struct Info& B) {
    if(A.to == B.to) {
        if(A.from == B.from) return true;
        return A.from < B.from;
    } else {
        return A.to < B.to;
    }
}

int n, c;
int m;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> c;
    cin >> m;
    struct Info info[m];
    for(int i = 0; i < m; ++i) {
        cin >> info[i].from >> info[i].to >> info[i].weight;
    }
    sort(info, info + m, comp);
    vector<int> bus(n, c);
    int ret = 0;
    for(int i = 0; i < m; ++i) {
        int start = info[i].from - 1;
        int end = info[i].to - 1;
        int minVal = 1e9;
        for(int i = start; i < end; ++i) {
            if(minVal > bus[i]) {
                minVal = bus[i];
            }
        }
        int adder = min(minVal, info[i].weight);
        ret += adder;
        for(int i = start; i < end; ++i) {
            bus[i] -= adder;
        }
    }
    cout << ret << "\n";
}
