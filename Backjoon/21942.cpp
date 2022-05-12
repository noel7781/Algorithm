#include <bits/stdc++.h>
using namespace std;
int N, F;
int D, H, M;
string L;
const int MONTH_TO_DAYS[] = {0, 31,28,31,30,31,30,31,31,30,31,30,31};
int psum_day[13];
map<pair<string, string>, int> borrow_list;
map<string, long long> result;
string s1, s2, book, name; 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> L >> F;
    D = stoi(L.substr(0, 3));
    H = stoi(L.substr(4, 2));
    M = stoi(L.substr(7, 2));
    H += (24 * D);
    M += (60 * H);
    for(int i = 1; i <= 12; i++) {
        psum_day[i] = psum_day[i-1] + MONTH_TO_DAYS[i];
    }

    for(int i = 0; i < N; i++) {
        cin >> s1 >> s2 >> book >> name;
        int month = stoi(s1.substr(5, 2));
        int day = stoi(s1.substr(8, 2));
        int hour = stoi(s2.substr(0, 2));
        int minute = stoi(s2.substr(3, 2));

        day += (psum_day[month-1]);
        hour += (24 * day);
        minute += (60 * hour);

        auto it = borrow_list.find({name, book});

        if(it == borrow_list.end()) {
            borrow_list.insert({{name, book}, minute});
        } else {
            long long price = max(0, minute - it->second - M);
            if(price > 0) {
                price *= F;
                result[name] += price;
            }
            borrow_list.erase(it);
        }

    }

    if(result.size() == 0) {
        cout << -1 << "\n";
        return 0;
    }
    for(auto it = result.begin(); it != result.end(); it++) {
        cout << it->first << " " << it->second << "\n";
    }
    return 0;

}