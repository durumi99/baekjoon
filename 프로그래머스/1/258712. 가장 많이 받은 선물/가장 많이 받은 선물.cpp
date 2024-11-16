#include <bits/stdc++.h>
#include <sstream>
using namespace std;
#define MAX 55

map <string, int> friends;
int table[MAX][MAX] = {0, };
int presentIndex[MAX] = {0, };

int solution(vector<string> _friends, vector<string> gifts) {
    int len = _friends.size();
    int answer = 0;
    int cnt = 0;
    for(auto f : _friends) {
        friends.insert({f, cnt++});
    }
    
    for(auto gift : gifts) {
        string a, b;
        stringstream stream; 
        stream.str(gift); 
        stream >> a >> b;
        table[friends[a]][friends[b]]++;
        presentIndex[friends[a]]++;
        presentIndex[friends[b]]--;   
    }
    
    int maxPresent = 0;
    int present[MAX] = {0, };
    for(int i = 0 ; i < len ; i++) {
        for(int j = i + 1 ; j < len ; j++) {
            int aPresent = table[i][j];
            int bPresent = table[j][i];
            if (aPresent != bPresent) { // 선물을 주고 받은 기록 있고 주고받은 선물 수가 다름 
                if (aPresent > bPresent) {
                    present[i]++;
                } else {
                    present[j]++;
                }
            } else { // 선물을 주고 받은 기록 없거나 주고 받은 선물 수가 같음
                int aIndex = presentIndex[i];
                int bIndex = presentIndex[j];
                if (aIndex > bIndex){
                    present[i]++;
                } else if(aIndex < bIndex) {
                    present[j]++;
                }
            }
        }
    }
    
    answer = *max_element(present, present + len);
    return answer;
}