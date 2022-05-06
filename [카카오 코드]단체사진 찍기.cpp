#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;


struct cond{
    char f1,f2;
    char op; // = : 0 , < : 1 , > : 2
    int dis;
    cond(char f1, char f2,int op,int dis): f1(f1), f2(f2),op(op),dis(dis){}
};
vector <cond> v;

bool satisfy(vector <char> names){
    int f1loc,f2loc;
    for(int i = 0 ; i < v.size() ; i++){
        auto it = find(names.begin(),names.end(),v[i].f1);
        f1loc = it - names.begin();
        it = find(names.begin(),names.end(),v[i].f2);
        f2loc = it - names.begin();
        
        if(v[i].op == '='){ // =
            if (abs(f1loc - f2loc) - 1 != v[i].dis)
                return false;
        }
        else if(v[i].op == '<'){ // <
            if (abs(f1loc - f2loc) - 1 >= v[i].dis)
                return false;
        }
        else{ // >
            if (abs(f1loc - f2loc) - 1 <= v[i].dis)
                return false;
        }
    }
    return true;
}
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    v.clear();
    int answer = 0;
    for(int i = 0 ; i < n ; i++){
        char f1 = data[i][0];
        char f2 = data[i][2];
        char op = data[i][3];
        int dis = data[i][4] - '0';
        v.push_back(cond(f1,f2,op,dis));
    }
    vector <char> names {'A','C','F','J','M','N','R','T'};
    sort(names.begin(),names.end());
    do{
        if(satisfy(names))
            answer++;
    }while(next_permutation(names.begin(),names.end()));
    
    return answer;
}