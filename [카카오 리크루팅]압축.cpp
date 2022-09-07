#include <string>
#include <vector>
#include <algorithm>

#include <iostream>

using namespace std;
vector<string> dic;
vector<int> solution(string msg) {
    vector<int> answer;
    dic.push_back(" ");
    for(int i = 0 ; i < 26 ; i++){
        string str(1,'A'+i);
        dic.push_back(str);
    }
    for(int i = 0 ; i < msg.length() ; i++){
        // cout << i << ' ';
        string tmp(1,msg[i]);
        int n = i;
        while(true){
            auto it = find(dic.begin(), dic.end(),tmp);
            if(it == dic.end()){ // 사전에 없는 경우
                dic.push_back(tmp); // 사전에 추가
                tmp.pop_back();
                auto it = find(dic.begin(), dic.end(),tmp);
                answer.push_back(it - dic.begin());
                i += tmp.length()-1;
                break;       
            }
            else{ // 사전에 있는 경우
                n++;
                if(n >= msg.length()){
                    auto it = find(dic.begin(), dic.end(),tmp);
                    answer.push_back(it - dic.begin());
                    i += tmp.length()-1;
                    break;
                }
                tmp += msg[n];
            }
        }
    }
    return answer;
}