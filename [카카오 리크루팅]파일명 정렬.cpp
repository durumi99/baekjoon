#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <iostream>
using namespace std;

bool cmp(pair<string,int> aa,pair<string,int> bb){
    string a = aa.first;
    string b = bb.first;
    string headA, headB;
    int numberA = 0, numberB = 0;
    // HEAD 와 NUMBER 추출
    int tmp = 0;
    while(!(a[tmp] >= '0' && a[tmp] <= '9')){
        headA += a[tmp];
        tmp++;
    }
    while(a[tmp] >= '0' && a[tmp] <= '9'){
        numberA *= 10;
        numberA += a[tmp]-'0';
        tmp++;
        if(tmp >= a.length())
            break;
    }
    tmp = 0;
    while(!(b[tmp] >= '0' && b[tmp] <= '9')){
        headB += b[tmp];
        tmp++;
    }
    while(b[tmp] >= '0' && b[tmp] <= '9'){
        numberB *= 10;
        numberB += b[tmp]-'0';
        tmp++;
        if(tmp >= b.length())
            break;
    }
    // 소문자로 통일
    for(int i = 0 ; i < headA.length() ; i++){
        if(headA[i] >= 'A' && headA[i] <= 'Z')
            headA[i] += 'a'-'A';
    }
    for(int i = 0 ; i < headB.length() ; i++){
        if(headB[i] >= 'A' && headB[i] <= 'Z')
            headB[i] += 'a'-'A';
    }
    
    if(headA == headB){ // HEAD가 같은 경우
        if(numberA == numberB) // NUMBER의 숫자도 같은 경우
            return aa.second < bb.second;
        return numberA < numberB;
    }
    return headA < headB;
}
vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector < pair<string,int> > tmpFiles;
    for(int i = 0 ; i < files.size() ; i++)
        tmpFiles.push_back({files[i],i+1});
    sort(tmpFiles.begin(),tmpFiles.end(),cmp);
    for(int i = 0 ; i < tmpFiles.size() ; i++)
        answer.push_back(tmpFiles[i].first);
    
    return answer;
}