#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 501
vector<int> solution(string s) {
    vector<int> answer;
    vector < vector<int> > v(MAX);
    
    int v_size = 0;
    vector <int> tmp;
    for(int i = 0 ; i < s.size() ; i++){
        if(s[i] >= '0' && s[i] <= '9'){
            int cur = i;
            while(s[cur] >= '0' && s[cur] <= '9'){
                cur++;
            }
            tmp.push_back(stoi(s.substr(i,cur-i+1)));
            i = cur-1;
        }
        else if(s[i] == '}'){
            v_size++;
            v[tmp.size()-1] = tmp;
            tmp.clear();
        }
    }
    v_size--;
    
    for(int i = 0 ; i < v_size ; i++){      
        for(int j = 0 ; j < v[i].size(); j++){
            if(find(answer.begin(),answer.end(),v[i][j]) == answer.end())
                answer.push_back(v[i][j]);
        }
    }
    return answer;
}