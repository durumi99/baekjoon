#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector < int > parking(10000); // first : 차번호, second : 입차 시간
vector < int > totaltime(10000); // first : 차번호, second : 누적 요금

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    int defT = fees[0];
    int defF = fees[1];
    int perT = fees[2];
    int perF = fees[3];
    parking.clear();
    totaltime.clear();
    
    for(int i = 0 ; i < records.size() ; i++){
        int time = stoi(records[i].substr(0,2)) * 60 + stoi(records[i].substr(3,2)) + 1;
        int num = stoi(records[i].substr(6,4));
        
        if(records[i].substr(11) == "IN"){
            parking[num] = time;
        }
        else{
            int parkingtime = time - parking[num];
            totaltime[num] += parkingtime;
            parking[num] = 0;
        }
    }
    for(int i = 0000 ; i < 10000 ; i++){
        if(parking[i]){
            int parkingtime = (24 * 60) - parking[i];
            totaltime[i] += parkingtime;
            parking[i] = 0;
        }
    }
    for(int i = 0000 ; i < 10000 ; i++){
        if(totaltime[i]){
            if(totaltime[i] < defT)
                answer.push_back(defF);
            else{
                int tmp = defF;
                tmp += ceil( (double)(totaltime[i] - defT) / (double)perT ) * perF;
                answer.push_back(tmp);
            }
        }
    }
    return answer;
}