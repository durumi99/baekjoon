#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector <string> buf;
    // cacheSize 가 0인 경우 예외처리
    if(cacheSize == 0){
        return cities.size() * 5;
    }
    for(int i = 0 ; i < cities.size(); i++){
        //소문자로 통일
        for(int j = 0 ; j < cities[i].length() ; j++){
            if(cities[i][j] >= 'A' && cities[i][j] <= 'Z')
                cities[i][j] -= 'A'-'a';
        }
        if(buf.size() == 0){
            answer += 5;
            buf.push_back(cities[i]);
        }
        else{
            auto it = find(buf.begin(), buf.end(), cities[i]);
            // cache miss
            if (it == buf.end()) { 
                answer+= 5;
                if(buf.size() == cacheSize)
                    buf.erase(buf.begin());
                buf.push_back(cities[i]);
            }
            // cache hit
            else {
                answer++;
                if(it-buf.begin() != cacheSize - 1){
                    buf.erase(it);
                    buf.push_back(cities[i]);
                }
            }
        }
    }
    return answer;
}