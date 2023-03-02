#include <iostream>
#include <string>
using namespace std;
string s;
int calPal(int idx1, int idx2) {
    int len = 0;
    
    while(true) {
        if(idx1 - len < 0 || idx2 + len >= s.length())
            break;
        if(s[idx1 - len] != s[idx2 + len])
            break;
        len++;
    }
    // cout << len * 2 - 1;
    if(idx1 == idx2)
        return len * 2 - 1;
    return len * 2;
}
int solution(string _s)
{
    int answer=0;
    s = _s;
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    for(int i = 0 ; i < s.length() ; i++) {
        answer = max(answer, calPal(i, i));
        if(i < s.length() - 1)
            answer = max(answer, calPal(i, i+1));
    }

    return answer;
}