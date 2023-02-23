#include <bits/stdc++.h>

using namespace std;
bool cmp(int a, int b) {
    string strA = to_string(a);
    string strB = to_string(b);
    
    return strA + strB > strB + strA;
}
string solution(vector<int> numbers) {
    string answer = "";
    
    sort(numbers.begin(), numbers.end(), cmp);
    for(auto number : numbers) {
        answer += to_string(number);
    }
    
    if(answer[0] == '0')
        answer = "0";
    
    return answer;
}
