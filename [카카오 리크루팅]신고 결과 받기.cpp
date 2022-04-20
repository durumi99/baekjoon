#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    int idSize = id_list.size();
    vector<int> answer(idSize);
    vector < vector <int> > report_list(idSize); 
    set <pair< string,string> > s; // set 을 이용해 중복을 제거한다.
    map <string,int> m; // 유저 ID 로 INDEX 접근한다.
    
    for(int i = 0 ; i < idSize ; i++){ // ex) m[muzi] = 0, m[frodo] = 1, ...
        m.insert({id_list[i],i});
    }
    
    for(int i = 0 ; i < report.size() ; i++){
        auto pos = report[i].find(" "); // 공백으로 두 ID 분리
        string userID = report[i].substr(0,pos);
        string reportedID = report[i].substr(pos+1,report[i].length()-1);
        s.insert({userID,reportedID});
    }
    for(auto iter = s.begin(); iter != s.end(); iter++){
        string userID = (*iter).first;
        string reportedID = (*iter).second;
        // INDEX로 변환 되어 저장 report_list[muzi] = {frodo,neo} -> report_list[0] = {1,3}
        report_list[m[reportedID]].push_back(m[userID]); 
    }
    
    for(int i = 0 ; i < idSize ; i++){
        if(report_list[i].size() >= k){ // 신고당한 회수가 k번 이상인 경우
            for(int j = 0 ; j < report_list[i].size() ; j++){
                answer[report_list[i][j]]++;
            }
        }
    }
    return answer;
}