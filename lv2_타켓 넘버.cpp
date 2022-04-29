#include <string>
#include <vector>
#include <queue>

using namespace std;


int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    queue <pair<string,int>> q; // <단어,변환 횟수>
    q.push({begin,0});
    int visited[51]= {0,};
    
    while(!q.empty()){
        string cur = q.front().first;
        int cnt = q.front().second;
        q.pop();
        
        if(cur == target){
            answer = cnt;
            break;
        }
        
        for(int i = 0 ; i < words.size(); i++){
            if(visited[i] == 1) // 이미 큐에 들어갔던 words는 넣지 않음
                continue;
            
            int dif = 0;
            for(int j = 0 ; j < words[i].length() ; j++){
                if(cur[j] != words[i][j])
                    dif++;
            }
            
            if(dif == 1){ // 다른 알파벳이 1개면 변환
                visited[i] = 1;
                q.push({words[i],cnt+1});
            }
            
        }
        
    }
    
    return answer;
}