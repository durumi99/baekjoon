#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#include <iostream>

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int min = 0;
    int zeroCnt = 0;
    for(int i = 0 ; i < lottos.size() ; i++){
        if(lottos[i] == 0)
            zeroCnt++;
        else{
            if ( find(win_nums.begin(),win_nums.end(),lottos[i]) != win_nums.end() ){
                min++;
                cout << lottos[i] << ' ';
            }
        }
    }
    int bestRank = 7 - (min+zeroCnt);
    if(bestRank == 7)
        bestRank--;
    int worstRank = 7 - min;
    if(worstRank == 7)
        worstRank--;
    
    answer.push_back(bestRank);
    answer.push_back(worstRank);
    return answer;
}