#include <bits/stdc++.h>

using namespace std;

struct Node {
    string data;
    int index;
    list<Node*> children;
};

Node reserve[15001];
int reserve_count = 1;

void print_room(Node* node, string add="") {
    for(auto it = node->children.begin(); it != node->children.end(); it++) {
        cout << add << (*it)->data << endl;
        print_room((*it), add + "--");
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N; cin >> N;
    Node root = reserve[0];
    for(int i = 0; i < 15001; i++) {
        reserve[i].index = i;
    }
    for(int i = 0; i < N; i++) {
        int K; cin >> K;
        int prev_number = 0;
        for(int j = 0; j < K; j++) {
            string s; cin >> s;
            reserve[reserve_count].data = s;
            if(reserve[prev_number].children.size() == 0) {
                reserve[prev_number].children.push_back(&reserve[reserve_count]);
                prev_number = reserve_count++;
            } else {
                bool is_added = false;
                for(auto it = reserve[prev_number].children.begin(); it != reserve[prev_number].children.end(); it++) {
                    if((*it)->data < s) continue;
                    else if((*it)->data == s) {
                        prev_number = (*it)->index;
                        is_added = true;
                        break;
                    } else {
                        if(it == reserve[prev_number].children.begin()) {
                            reserve[prev_number].children.push_front(&reserve[reserve_count]);
                        } else {
                            reserve[prev_number].children.insert(it, &reserve[reserve_count]);
                        }
                        prev_number = reserve_count++;
                        is_added = true;
                        break;
                    }
                }
                if(!is_added) {
                    reserve[prev_number].children.push_back(&reserve[reserve_count]);
                    prev_number = reserve_count++;
                }
            }
        }
    }
    print_room(&reserve[0]);
}