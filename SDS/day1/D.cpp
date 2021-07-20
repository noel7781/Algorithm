#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int ord_cc[101];
int num_cc;
int pic_frame[20];
int cand_like[101];
int cand_where[101];
int cand_when[101];

int get_pic_frame() {
    for(int i = 0; i < n; i++) {
        if(pic_frame[i] == 0) {
            return i;
        }
    }
    int res = 0;
    int cnt_min = 1000;
    int cnt_when = 1000;
    for(int i = 0; i < n; ++i) {
        int cand = pic_frame[i];
        if(cnt_min > cand_like[cand] || (cnt_min == cand_like[cand] && cnt_when > cand_when[cand])) {
            res = i;
            cnt_min = cand_like[cand];
            cnt_when = cand_when[cand];
        }
    }
    return res;
}

int main() {
    scanf("%d", &n);
    scanf("%d", &num_cc);
    for (int i = 0 ; i < num_cc ; i++) {
        scanf("%d", &ord_cc[i]);
    }

    // 초기화 
    for (int i = 1 ; i <= 100 ; i++) {
        cand_where[i] = -1;
        cand_when[i] = -1;
    }

    // 추천을 수행한다 .... num_cc만큼
    for (int i = 0 ; i < num_cc ; i++) {
        // ord_cc[i]
        int cur = ord_cc[i];
        // 후보가 사진틀에 올라가 있을까?
        if (cand_where[cur] != -1) {
            // 좋아요만 올려줌 
            cand_like[cur]++;
        }
        else {
            // 비어있는 또는 후보를 넣을 사진틀을 얻는다. 
            int pos = get_pic_frame();
            int delete_cand = pic_frame[pos];
            // delete_cand는 사진틀에서 내리면서, 좋아요도 초기화한다
            if (delete_cand != 0) {
                cand_where[delete_cand] = -1;
                cand_like[delete_cand] = 0;
            }           
            cand_where[cur] = pos;
            cand_like[cur] = 1;
            cand_when[cur] = i;
            pic_frame[pos] = cur;
        }       
    }

    // 정답을 출력한다
    // pic_frame을 조사해서, 누가 사진틀에 있는지확인하고,
    // 후보들을 모아서 번호가 증가하는 순서대로 출력한다..
    for (int i = 1 ; i <= 100 ; i++) {
        if (cand_where[i] != -1) {
            printf("%d ", i);
        }
    }
}