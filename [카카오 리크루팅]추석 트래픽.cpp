#include <string>
#include <vector>
#include <sstream>
#include <map>

#include <iostream>
using namespace std;

map <double,int> traffic;

int solution(vector<string> lines) {
    int answer = 0;
    for(int i = 0 ; i < lines.size() ;i++){
        stringstream stream; 
        stream.str(lines[i]);
        string start,process;
        stream >> process >> start >> process;
        process.erase(process.end()-1);
        int endTime = stoi(start.substr(0,2)) * 60 * 60 * 1000 + stoi(start.substr(3,2)) * 60 * 1000 + stod(start.substr(6)) * 1000; 
        int startTime = endTime - stod(process) * 1000 + 1;
        for(int j = startTime ; j <= endTime + 999; j++){            
            if(traffic.find(j) == traffic.end()){
                traffic.insert({j,1});
            }
            else{
                traffic[j]++;
            }
            answer = traffic[j] > answer ? traffic[j] : answer; 
        }
    }   
    return answer;
}