#include <string>
#include <vector>
#include <map>

using namespace std;

string END_TIME = "23:59";

int str2int(string& str) {
	int hours = stoi(str.substr(0, 2));
    int minutes = stoi(str.substr(3, 2));
    return hours * 60 + minutes;
}

int getTimeDiff(string& t1, string& t2) {
    return abs(str2int(t2) - str2int(t1));
}

map<string, int> ans;
map<string, string> mapNumAndTime;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    for(const auto record: records) {
        string time = record.substr(0, 5);
        string num = record.substr(6, 4);
        string state = record.substr(11);
        if(state == "OUT") {
            int timeDiff = getTimeDiff(time, mapNumAndTime[num]);
            mapNumAndTime.erase(num);
            ans[num] += timeDiff;
        } else {
            mapNumAndTime[num] = time;
        }
    }
    for(auto it: mapNumAndTime) {
        int timeDiff = getTimeDiff(END_TIME, it.second);
        ans[it.first] += timeDiff;
    }
    for(auto it: ans) {
        int time = it.second;
        int cost = fees[1];
        time -= fees[0];
        if(time > 0) {
            cost += ((time / fees[2] + !!(time % fees[2])) * fees[3]);
        }
        answer.push_back(cost);
    }
    return answer;
}