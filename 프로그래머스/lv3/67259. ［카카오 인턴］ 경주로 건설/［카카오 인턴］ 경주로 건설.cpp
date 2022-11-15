#include <string>
#include <vector>
#include <utility>
#include <iostream>

using namespace std;
vector < vector <int> > globalBoard;
pair <int, int> dp[30][30];
int dstX, dstY;
int answer = -1;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int getManhattanDist (int curX, int curY) {
    if (curX == dstX) {
        return (dstY - curY) * 100;
    }
    if (curY == dstY) {
        return (dstX - curX) * 100;
    }
    return ((dstX - curX) + (dstY - curY)) * 100 + 500;
}
void dfs(int curX, int curY, int curCost, int curDir) { // 0: right, 1: down, 2: left, 3: up
    if (answer != -1 && curCost + getManhattanDist(curX, curY) >= answer) {
        return;
    }
    
    if (dp[curY][curX].first == -1 || dp[curY][curX].first >= curCost) {
        dp[curY][curX].first = curCost;
        dp[curY][curX].second = curDir;
    } else if (dp[curY][curX].second != curDir && (curDir == 0 || curDir == 1)) {
        dp[curY][curX].first = curCost;
        dp[curY][curX].second = curDir;
    } else {
        return;
    }
    
    if (curX == dstX && curY == dstY) {
        if (answer == -1) {
            answer = curCost;
        } else {
            answer = answer > curCost ? curCost : answer; 
        }
        return; 
    }
    
    int newX = curX + dx[curDir];
    int newY = curY + dy[curDir];
    
    if (newX >= 0 && newX <= dstX && newY >= 0 && newY <= dstY && globalBoard[newY][newX] == 0) {
        globalBoard[newY][newX] = 1;
        dfs(newX, newY, curCost+100, curDir);
        globalBoard[newY][newX] = 0;
    }
    
    for (int i = 0 ; i < 4 ; i++) {
        if(curDir == i)
            continue;
        
        int newX = curX + dx[i];
        int newY = curY + dy[i];
        
        if(newX < 0 || newX > dstX || newY < 0 || newY > dstY)
            continue;
        if(globalBoard[newY][newX] == 1)
            continue;
        
        globalBoard[newY][newX] = 1;
        dfs(newX, newY, curCost + 600, i);
        globalBoard[newY][newX] = 0;
    }
}

int solution(vector<vector<int>> board) {
    for (int i = 0; i < board.size() ; i++) {
        for (int j = 0 ; j < board[i].size(); j++) {
            dp[i][j].first = -1;
            dp[i][j].second = -1;
        }
    }

    globalBoard = board;
    dstX = dstY = board.size() - 1;
    globalBoard[0][0] = 1;
    
    for (int i = 0 ; i < 2 ; i++) {
        dfs(0, 0, 0, i);
    }
    return answer;
}