#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

#include <iostream>

void f(string& str, vector <string> &v){
    for(int i = 0 ; i < str.length() - 1; i++){
        // 대문자로  통일
        if(str[i] >= 'a' && str[i] <= 'z') 
            str[i] += 'A'-'a';
        if(str[i+1] >= 'a' && str[i+1] <= 'z')
            str[i+1] += 'A'-'a';
        // 유효글자 쌍이 아니면 버린다
        if(str[i] < 'A' || str[i] > 'Z' || str[i+1] < 'A' || str[i+1] > 'Z')
            continue;
        v.push_back(str.substr(i,2));
    }
    return;
}

int j(vector <string> v1, vector <string> v2){
    if(v1.size() == 0 && v2.size() == 0) 
        return 65536;
    int _union;
    vector <string> intersection;
    
    for(int i = 0 ; i < v1.size() ; i++){
        auto ptr = find(v2.begin(),v2.end(),v1[i]); // 같은 원소 탐색
        if(ptr != v2.end()){
            intersection.push_back(v1[i]);
            *ptr = ""; // 탐색 후 지워줌
        }
    }
    
    _union = v1.size() + v2.size() - intersection.size();
    
    return ((double)intersection.size() / (double)_union) * 65536;
}
int solution(string str1, string str2) {
    int answer = 0;
    vector <string> v1,v2;

    f(str1,v1);
    f(str2,v2);
    answer = j(v1,v2);
    
    return answer;
}