#include <string>
#include <vector>
#include <map>
#include <algorithm>

#include <iostream>
using namespace std;


vector<int> solution(vector<string> gems) {
    vector<int> answer;
    map <string,int> gemType;
    int minStart = -1 ,minEnd = gems.size();

    for(int i = 0 ; i < gems.size() ; i++){
        gemType[gems[i]]++;
    }   
    int totalSize = gemType.size();
    int start = 0,end = 0;
    map <string,int> tmp;
    tmp[gems[0]]++;
    while(start <= end && end < gems.size()){
        if(totalSize == tmp.size()){
            if(end - start < minEnd - minStart){
                minEnd = end;
                minStart = start;
            }
            tmp[gems[start]]--;
            if(tmp[gems[start]] == 0)
                tmp.erase(gems[start]);
            start++;
            continue;
        }
        if(end == gems.size() - 1)
            break;
        tmp[gems[++end]]++;        
        if(gems[end] == gems[start] || gems[start+1] == gems[start]){
            tmp[gems[start++]]--;
        }
    }
      
    answer.push_back(minStart+1);
    answer.push_back(minEnd+1);
    return answer;
}