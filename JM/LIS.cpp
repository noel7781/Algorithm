#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n;
int cache[101], S[100], choices[101];

int lis(int start) {
    int& ret = cache[start+1];
    if(ret != -1)
        return ret;
    ret = 0;
    int bestNext = -1;
    for(int next = start+1; next < n; ++next) {
        if(start == -1 || S[start] < S[next]) {
            int cand = lis(next) + 1;
            if(cand > ret) {
                ret = cand;
                bestNext = next;
            }
        }
    }
    choices[start+1] = bestNext;
    return ret;
}

void reconstruct(int start, vector<int>& seq) {
    if(start != -1) seq.push_back(S[start]);
    int next = choices[start+1];
    if(next != -1) reconstruct(next, seq);
}

int main() {
    memset(cache, -1, sizeof(cache));
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> S[i];
    }
    cout << lis(-1) << "\n";
    for(int i = 0; i <=  n; ++i) {
        printf("choices[%d]: %d\n", i, choices[i]);

    }
    vector<int> result;
    reconstruct(-1, result);
    for(auto it: result) {
        cout << it << "\n";
    }
}
