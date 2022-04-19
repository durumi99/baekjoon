#include <string>
#include <vector>
#include <stack>

#include <iostream>
using namespace std;

stack <int> s;
int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    for(int i = 0 ; i < moves.size() ; i++){
        int tmp = moves[i] - 1;
        int j = 0;
        while(j < board.size() && board[j][tmp] == 0){
            j++;
        }
        if(j == board.size())
            continue;
        
        int doll = board[j][tmp];
        board[j][tmp] = 0;
        
        if(doll == 0)
            continue;
        if(!s.empty() && s.top() == doll){
            s.pop();
            answer += 2;
        }
        else{
           s.push(doll);
        }       
    }
    return answer;
}