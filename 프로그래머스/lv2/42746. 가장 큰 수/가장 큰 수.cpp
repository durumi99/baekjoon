#include <bits/stdc++.h>

using namespace std;
bool cmp(int a, int b) {
    string strA = to_string(a);
    string strB = to_string(b);
    
    string tmp1 = strA + strB;
    string tmp2 = strB + strA;
    
    return tmp1 > tmp2;
}
string solution(vector<int> numbers) {
    string answer = "";
    sort(numbers.begin(), numbers.end(), cmp);
    for(auto number : numbers) {
        answer += to_string(number);
    }
    if(answer[0] == '0' && answer[answer.length()-1] == '0')
        return "0";
    
    return answer;
}