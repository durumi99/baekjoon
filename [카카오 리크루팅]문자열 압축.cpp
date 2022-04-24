#include <string>
#include <vector>
#include <iostream>
using namespace std;

int compression(string s, int unit){
    string ss;
    int length = 0;
    for(int i = 0 ; i < s.length() ; i += unit){
        int tmp = i + unit;
        bool flag = true;
        while( ( (tmp+unit) <= s.length() )&& s.substr(i,unit) == s.substr(tmp,unit)){
            tmp += unit;
            flag = false;
        }
        if(flag){
            length += unit;
            ss += s.substr(i,unit);
            continue;
        }
        length += unit + 1;
        ss += to_string( (tmp-i) / unit);
        ss += s.substr(i,unit);
        i = tmp - unit;
    }
    length = ss.length();
    return length;
}
int solution(string s) {
    int answer = 0;
    answer = s.length();
    for(int i = s.length() / 2 ; i >= 1 ; i--){
        int tmp = compression(s,i);
        answer = (tmp < answer) ? tmp : answer;
    }
    return answer;
}