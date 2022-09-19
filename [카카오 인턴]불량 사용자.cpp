#include <string>
#include <vector>
#include <set>

#include <iostream>

using namespace std;
set <string> curBannedId;
set < set<string> > s;
int banidSize;
bool checkMatch(string userId, string bannedId){
    if(userId.length() != bannedId.length())
        return false;
    for(int i = 0 ; i < userId.length() ; i++){
        if(userId[i] == '*')
            continue;
        if(userId[i] != bannedId[i])
            return false;
    }
    return true;
}

void dfs(vector<string> user_id, vector<string> banned_id,int idx){
    if(curBannedId.size() == banidSize){
        s.insert(curBannedId);
        return;
    }
    for(int i = idx ; i < banned_id.size() ; i++){
        for(int j = 0 ; j < user_id.size() ; j++){
            // curBannedId에 이미 들어가있으면 넘어감
            if(curBannedId.find(user_id[j]) != curBannedId.end())
                continue;
            if(checkMatch(banned_id[i],user_id[j])){
                curBannedId.insert(user_id[j]);
                dfs(user_id,banned_id,i+1);
                curBannedId.erase(user_id[j]);
            }
        }
    }
}
int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    banidSize = banned_id.size();
    dfs(user_id,banned_id,0);
    
    answer = s.size();
    return answer;
}