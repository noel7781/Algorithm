#include <bits/stdc++.h>
using namespace std;
int N;
vector<int> V;
struct Trie {
    bool terminal = false;
    Trie* children[2];
    Trie() {
        for(int i = 0; i < 2; i++) {
            children[i] = NULL;
        }
        terminal = false;
    }
    ~Trie() {
        for(int i = 0; i < 2; i++) {
            if(children[i]) delete (children[i]);
        }
    }
    void insert(int num, int bits) {
        if(bits < 0) {
            terminal = true;
            return;
        }
        int next = (num & (1 << bits)) ? 1 : 0;
        if(children[next] == NULL) {
            children[next] = new Trie();
        }
        children[next]->insert(num, bits-1);
    }
    int solve(int num, int bits) {
        if(bits < 0) return 0;
        int next = (num & (1 << bits)) ? 0 : 1;
        int ret = 0;
        if(children[next] == NULL) next ^= 1;
        else ret |= (1 << bits);
        return ret + children[next]->solve(num, bits-1);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N; V.resize(N); for(auto &it: V) cin >> it;
    Trie * t = new Trie();
    for(auto it: V) {
        t->insert(it, 31);
    }
    int ret = 0;
    for(int i = 0; i < N; i++) {
        ret = max(ret, t->solve(V[i], 31));
    }
    cout << ret << "\n";
    delete t;
}