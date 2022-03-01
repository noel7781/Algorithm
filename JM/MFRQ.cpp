#include <iostream>
using namespace std;
struct RangeResult {
    int size; // 구간의 크기
    int mostFrequent; // 가장 자주 등장하는 숫자의 출현 횟수
    int leftNumber, leftFreq; // 왼쪽 끝 숫자와 왼쪽 끝 숫자의 출현 횟수
    int rightNumber, rightFreq; // 오른쪽 끝 숫자와 오른쪽 끝 숫자의 출현 횟수


};

RangeResult merge(const RangeResult& a, const RangeResult& b) {
    RangeResult ret;
    ret.size = a.size + b.size;
    ret.leftNumber = a.leftNumber;
    ret.leftFreq = a.leftFreq;
    if(a.size == a.leftFreq && a.leftNumber == b.leftNumber) {
        ret.leftFreq += b.leftFreq;
    }
    ret.rightNumber = b.rightNumber;
    ret.rightFreq = b.rightFreq;
    if(b.size == b.rightFreq && a.rightNumber == b.rightNumber) {
        ret.rightFreq += a.rightFreq;
    }
    ret.mostFrequent = max(a.mostFrequent, b.mostFrequent);
    if(a.rightNumber == b.leftNumber) {
        ret.mostFrequent = max(ret.mostFrequent, a.rightFreq + b.leftFreq);
    }
    return ret;
}