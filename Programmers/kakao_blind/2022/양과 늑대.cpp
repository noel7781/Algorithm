#include<iostream>
#include <string>
#include <vector>
using namespace std;
vector<vector<int>> adj;
int len = 0;
int ans = 0;
void search(vector<int>& info, int cur, int next, int sheep, int wolf) {
    int nextSheep = sheep;
    int nextWolf = wolf;
    if(info[cur] == 0) nextSheep++;
    else nextWolf++;
    if(nextWolf >= nextSheep) return;
    ans = max(ans, nextSheep);
    next &= ~(1 << cur);
    for(auto it: adj[cur]) next |= (1 << it);
    for(int i = 0; i < len; i++) {
        if(next & (1 << i)) {
            search(info, i, next, nextSheep, nextWolf);
        }
    }
    return;
}

int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 0;
    len = info.size();
    adj.resize(len);
    for(const auto edge: edges) {
    	adj[edge[0]].push_back(edge[1]);
    }
    search(info, 0, 0, 0, 0);
    answer = ans;
    return answer;
}