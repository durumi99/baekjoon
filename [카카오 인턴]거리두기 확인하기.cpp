#include <string>
#include <vector>
#include <iostream>
#include <utility>

#define roomCol 5
#define roomRow 5

using namespace std;
bool isGood(vector <string> place){
    vector < pair<int,int> > loc;
    int dis;
    
    for(int i = 0 ; i < roomCol ; i++){
        for(int j = 0 ; j < roomRow ; j++){
            if(place[i][j] == 'P'){
                for(int k = 0 ; k < loc.size() ; k++){
                    int xDiff = abs(loc[k].first-i);
                    int yDiff = abs(loc[k].second-j);
                    int xMid = (loc[k].first + i ) / 2;
                    int yMid = (loc[k].second + j ) / 2;
                    
                    dis = xDiff + yDiff;
                    if(dis == 1){
                        return false;
                    }
                    else if(dis == 2){
                        if(xDiff == 2){
                            if(place[xMid][j] == 'O')
                                return false;
                        }
                        else if(yDiff == 2){
                            if(place[i][yMid] == 'O')
                                return false;
                        }
                        else{ // xDiff = 1 , yDiff = 1
                            if(place[i][loc[k].second] == 'O' || place[loc[k].first][j] == 'O')
                                return false;
                        }
                    }
                }
                loc.push_back({i,j});
            }
        }
    }
    return true;
}
vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(int i = 0 ; i < 5 ; i++){
        if(isGood(places[i]))
            answer.push_back(1);
        else{
            answer.push_back(0);
        }
    }
    return answer;
}