#include <bits/stdc++.h>

#define MAX 1000001
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end());
    for(int i = 0 ; i < phone_book.size()-1 ; i++) {
        string cur = phone_book[i];
        string next = phone_book[i+1];
        int curLen = cur.length();
        int nextLen = next.length();
        if(curLen >= nextLen)
            continue;
        if(cur == next.substr(0, curLen)) {
            answer = false;
            break;
        }
    }
    return answer;
}