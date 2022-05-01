#include <string>
#include <vector>
#include <stack>

#include <iostream>
using namespace std;

string makeCorStr(string p){
    // 1. 빈 문자열이면 return
    if(p == "")
        return p;
    
    // u,v 로 분리
    string u,v;
    int tok = 0;
    bool isUCorrect = false;
    stack <char> s;
    int leftCnt = 0;
    int rightCnt = 0;
    
    for(int i = 0 ; i < p.length() ; i++){ 
        
        if(p[i] == '('){
            s.push('(');
            leftCnt++;
        }
        else {
            if(!s.empty())
                s.pop();
            rightCnt++;
        }
        if(tok == 0 && leftCnt == rightCnt){
            if(s.empty())
                isUCorrect = true;
            tok = i;
        }
    }
    if(s.empty()) // p가 올바른 괄호 문자열인 경우
        return p;
    u = p.substr(0,tok+1);
    v = p.substr(tok+1,p.length()-tok-1);
    if(isUCorrect){
        u += makeCorStr(v); // 3. u가 올바른 문자열인 경우
        return u;
    }
    // 4.u가 올바른 괄호 문자열이 아닌 경우
    string tmp = "(";
    tmp += makeCorStr(v);
    tmp += ")";
    for(int i = 1 ; i < u.length()-1 ; i++){
        if(u[i] == '(')
            tmp += ")";
        else
            tmp += "(";
    }
    return tmp;
}
string solution(string p) {
    string answer = "";
    answer = makeCorStr(p);
    return answer;
}