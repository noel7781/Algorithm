#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <map>
using namespace std;
int adj[1002][1002];
vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    map<string, int> name_to_index;
    int id = 1;
    for(const auto& it: id_list) {
        if(name_to_index[it] == 0) {
            name_to_index[it] = id++;
        }
    }
    vector<int> answer(id-1, 0);
    for(int i = 0; i < report.size(); i++) {
        stringstream ss(report[i]);
        string str;
        vector<string> vs;
        while(getline(ss, str, ' ')) {
            vs.push_back(str);
        }
        int reporter = name_to_index[vs[0]]-1;
        for(int i = 1; i < vs.size(); i++) {
            int reported = name_to_index[vs[i]]-1;
            adj[reported][reporter] = 1;
        }
    }
    for(int i = 0; i < id-1; i++) {
        vector<int> v;
        for(int j = 0; j < id-1; j++) {
            if(adj[i][j]) v.push_back(j);
        }
        if(v.size() >= k) {
            for(auto x: v) answer[x]++;
        }
    }
    return answer;
}