#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

vector <long long> num;
vector <char> op;

void input(string expression){
    long long tmp = 0;
    for(int i = 0 ; i < expression.length() ; i++){
        if(expression[i] >= '0' && expression[i] <= '9'){
            tmp = tmp * 10 + (expression[i]-'0');
        }
        else{
            num.push_back(tmp);
            tmp = 0;
            op.push_back(expression[i]);
        }
    }
    num.push_back(tmp);
}

long long f(vector <char> precedence){
    long long tmp = 0;
    vector <long long> tmpNum = num;
    vector <char> tmpOp = op;
    
    for(int i = 0 ; i < precedence.size() ; i++){
        for(int j = 0 ; j < tmpOp.size(); j++){
            if(tmpOp[j] == precedence[i]){                
                if(tmpOp[j] == '+')
                    tmpNum[j] += tmpNum[j+1];
                else if(tmpOp[j] == '*')
                    tmpNum[j] *= tmpNum[j+1];
                else
                    tmpNum[j] -= tmpNum[j+1];
                tmpOp.erase(tmpOp.begin()+j);
                tmpNum.erase(tmpNum.begin()+j+1);
                j--;
            }
        }
    }
    return abs(tmpNum[0]);
}
long long solution(string expression) {
    long long answer = 0;
    num.clear();
    op.clear();
    input(expression);
    
    vector <char> precedence = {'*','-','+'};
    sort(precedence.begin(),precedence.end());
    long long maxN;
    do{
        maxN = f(precedence);
        answer = (maxN > answer) ? maxN : answer;
    }while(next_permutation(precedence.begin(),precedence.end()));
    
    return answer;
}