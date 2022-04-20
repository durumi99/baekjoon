#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, double> pid;

bool comp(pair<int, double>& a, pair<int, double>& b){
    if(a.second > b.second) return true;
    else if(a.second == b.second){
        return a.first <= b.first;
    } else{
        return false;
    }
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<int> tmp(N+1);
    vector<pid> v;
    int userCnt = stages.size();
    
    for(int i = 0 ; i < stages.size() ; i++){
        tmp[stages[i]]++;
    }
    
    for(int i = 1 ; i <= N ; i++){
        if(userCnt == 0)
            v.push_back({i,0});
        else
            v.push_back({i,(double)tmp[i]/(double)userCnt});
        userCnt -= tmp[i];
    }
    
    sort(v.begin(),v.end(),comp);
    for(int i = 0 ; i < v.size() ; i++)
        answer.push_back(v[i].first);
    return answer;
}