#include <string>
#include <vector>

using namespace std;

int diff = 0;

void search(vector<int>& info, vector<int>& answer, vector<int>& sub, int left, int pos) {
    if(left == 0) {
        int peach = 0, lion = 0;
        for(int i = 0; i < 11; i++) {
            if(info[i] == 0 && sub[i] == 0) continue;
            if(info[i] >= sub[i]) peach += (10 - i);
            else lion += (10 - i);
        }
        if(lion <= peach) return;
        if(diff < (lion - peach)) {
            diff = lion - peach;
            answer = sub;
        } else if(diff == (lion - peach)) {
            for(int i = 10; i >= 0; i--) {
                if(sub[i] == answer[i]) continue;
                if(sub[i] > answer[i]) {
                    answer = sub;
                    break;
                } else {
                    break;
                }
            }
        }
        return;
    }
    if(pos > 10) return;
    search(info, answer, sub, left, pos+1);
    sub[pos] += 1;
    search(info, answer, sub, left-1, pos);
    sub[pos] -= 1;
    return;
}

vector<int> solution(int n, vector<int> info) {
    vector<int> answer;
    vector<int> sub(11, 0);
    search(info, answer, sub, n, 0);
    if(answer.size() == 0) answer.push_back(-1);
    return answer;
}