#include <string>
#include <vector>

#include <iostream>

using namespace std;
// n진수로 변환하는 함수
void convertN(int num,int n,string &str){
    if(num == 0)
        return;
    convertN(num / n , n,str);
    
    if(num % n >= 10)
        str += 'A' + num % n - 10;
    else
        str += to_string(num % n);
}
string solution(int n, int t, int m, int p) {
    string answer = "";
    string str = "0";
    
    int tmp = 0;
    while(str.length() <= t * m){
        tmp++;
        convertN(tmp,n,str);
    }
    
    for(int i = 0 ; i < t * m ; i++){
        if(i % m == (p-1) ){ // tube가 말할 차례
            answer.push_back(str[i]);   
        }
    }
    return answer;
}