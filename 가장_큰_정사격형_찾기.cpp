#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0,row = board.size(),col = board[0].size();
    int map[row+1][col+1] ;
    for (int i = 0 ; i <= row; i++) {
        map[i][0] = 0;
    }
    for (int i = 0 ; i <= col; i++) {
        map[0][i] = 0;
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            map[i + 1][j + 1] = board[i][j];
        }
    }
    
    for(int i = 1 ; i <= row ; i++){
        for(int j = 1 ; j <= col ; j++){
            if(map[i][j] != 0){
                map[i][j] = min(map[i-1][j-1],min(map[i-1][j],map[i][j-1]))+1;
                answer = max(map[i][j],answer);
            }
        }       
    }
    
    return answer*answer;
}