#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;
//ENTER 0 , LEAVE 1 , CHANGE 2
vector<string> solution(vector<string> record) {
    vector<string> answer;
    map <string,string> m;
    vector <string> act;
    vector <string> uid;
    vector <string> nick;
    for(int i = 0 ; i < record.size() ; i++){

        int prev = 0;
        int cur = 0;
        string tmp;
        
        cur = record[i].find(" ",prev);
        tmp = record[i].substr(prev,cur-prev);
        prev = cur + 1;
        act.push_back(tmp);
        
        cur = record[i].find(" ",prev);
        tmp = record[i].substr(prev,cur-prev);
        prev = cur + 1;
        uid.push_back(tmp);
        
        cur = record[i].find(" ",prev);
        tmp = record[i].substr(prev,cur-prev);
        prev = cur + 1;
        nick.push_back(tmp);
    }
    
    for(int i = 0 ; i < record.size() ; i++)
    {
        if(act[i] == "Enter" || act[i] == "Change"){
            auto item = m.find(uid[i]);
            if(item == m.end())
                m.insert({uid[i],nick[i]});
            else
                m[uid[i]] = nick[i];
        }
    }
    for(int i = 0 ; i < record.size() ; i++){
        string tmp = m[uid[i]];
        if(act[i] == "Enter")
            tmp += "님이 들어왔습니다.";
        else if(act[i] == "Leave")
            tmp += "님이 나갔습니다.";
        else
            continue;
        answer.push_back(tmp);
    }
    return answer;
}