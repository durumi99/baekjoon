#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

map <string,int> m;

void Combination(string s,string comb,int r, int idx, int depth){
    if(r == 0){
        if(m.find(comb) == m.end())
            m.insert({comb,1});
        else
            m[comb]++;
    }
    else if(depth == s.length())
        return;
    else{
        comb += s[depth];
        Combination(s,comb,r-1,idx+1,depth+1);
        comb.erase(comb.begin()+comb.length()-1);
        Combination(s,comb,r,idx,depth+1);
    }
}
void makeCourse(vector<string> &answer,vector<string> orders, int menuCnt){
    int maxN = 0;
    m.clear();
    
    for(int i = 0 ; i < orders.size() ; i++){
        sort(orders[i].begin(),orders[i].end());
        Combination(orders[i],"",menuCnt,0,0);
    }
    
    for(auto iter = m.begin() ; iter != m.end() ; ++iter)
        if(iter->second > maxN)
            maxN = iter->second;
    
    if(maxN < 2)
        return;
    
    for(auto iter = m.begin() ; iter != m.end() ; ++iter)
        if(iter->second == maxN)
            answer.push_back(iter->first);        
    
    return;
}
vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    for(int i = 0 ; i < course.size() ; i++){
        makeCourse(answer,orders,course[i]);
    }
    
    sort(answer.begin(),answer.end());
    return answer;
}