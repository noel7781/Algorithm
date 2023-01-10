#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

struct t_time {
    int month;
    int day;
};

typedef pair<t_time, t_time> ptt;

int n;
vector<ptt> days;
int DAYS[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

bool comp(ptt& a, ptt& b) {
    if(a.second.month == b.second.month) {
        if(a.second.day == b.second.day)  {
            if(a.first.month == b.first.month) {
                if(a.first.day == b.first.day) {
                    return false;
                } else {
                    return a.first.day < b.first.day;
                }
            } else {
                return a.first.month < b.first.month;
            }
        } else {
            return a.second.day < b.second.day;
        }
    } else {
        return a.second.month < b.second.month;
    }
}

int select(int month, int day, int pos) {
    int last_idx = -1;
    for(int i = pos+1; i < n; ++i) {
        if((days[i].first.month < month || (days[i].first.month == month && days[i].first.day <= day)) && (days[i].second.month > month || (days[i].second.month == month && days[i].second.day > day))) {
            last_idx = i;
        }
    }
    return last_idx;
}

int solve() {
    int ret = 0;
    int month = 3, day = 1;
    int pos = -1;
    int next = 0;
    while(true) {
        next = select(month, day, pos);
        if(next == -1) {
            break;
        }
        month = days[next].second.month;
        day = days[next].second.day;
        pos = next;

        ret += 1;

        if(month >= 12) {
            break;
        }

    }
    if(next == -1) {
        if(month >= 12) {
            return ret;
        } else {
            return 0;
        }
    }
    return ret;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; ++i) {
        int m1, d1, m2, d2; cin >> m1 >> d1 >> m2 >> d2;
        t_time start = {m1, d1};
        t_time end = {m2, d2};
        days.push_back(make_pair(start, end));
    }
    sort(days.begin(), days.end(), comp);
    
    cout << solve() << "\n";

}
