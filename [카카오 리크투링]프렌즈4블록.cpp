#include <string>
#include <vector>
#include <utility>
#include <set>
#include <iostream>
using namespace std;

bool findBlock(int i, int j, vector<string> board){
    if(board[i][j] == '*')
        return false;
    if(board[i][j] == board[i][j+1] && board[i][j] == board[i+1][j] && board[i][j] == board[i+1][j+1])
        return true;
    return false;
}

void moveBlock(int i, int j, vector<string> &board,int m){
    for(int k = i ; k > 0 ; k--){
        board[k][j] = board[k-1][j];
        board[k-1][j] = '*';
    }
}
int check2x2(int m, int n, vector<string> &board){
    int cnt = 0;
    set < pair<int,int> > s; 
    //2x2가 완성된 블록을 찾는다
    for(int i = 0 ; i < m-1 ; i++){
        for(int j = 0 ; j < n-1 ; j++){
            if(findBlock(i,j,board) == true){
                s.insert({i,j});
                s.insert({i,j+1});
                s.insert({i+1,j});
                s.insert({i+1,j+1});
            }
        }
    }
    cnt += s.size();
    // 블록들을 지운다
    for (auto it = s.begin(); it != s.end(); it++) {
        int i = it->first;
        int j = it->second;
        moveBlock(i,j,board,m);
    }
    return cnt;
}
int solution(int m, int n, vector<string> board) {
    int answer = 0;
    int tmp = 0;
    while(true){
        tmp = check2x2(m,n,board);
        if(tmp == 0)
            break;
        answer += tmp;
    }
    return answer;
}