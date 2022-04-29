#include <vector>
#include <queue>

using namespace std;

#define MAX 101
int visited[MAX][MAX] = {0,};
int maxArea = 0;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.

int bfs(int x, int y , int m, int n, vector<vector<int>> picture){
    int curArea = 1;
    int color = picture[x][y];
    queue < pair<int,int> > q;
    q.push({x,y});
    visited[x][y] = 1;
    
    while(!q.empty()){
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();
        
        for(int i = 0 ; i < 4 ; i++){
            int newX = curX + dx[i];
            int newY = curY + dy[i];
            if(newX < 0 || newY < 0 || newX >= m || newY >= n)
                continue;
            if(visited[newX][newY])
                continue;
            if(picture[newX][newY] != color)
                continue;
            q.push({newX,newY});
            curArea++;
            visited[newX][newY] = 1;
        }
    }
    return curArea;
}
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
      
    for(int i = 0 ; i < m ; i++ )
        for(int j = 0 ; j < n ; j++)
            visited[i][j] = 0;
    
    for(int i = 0 ; i < m ; i++ )
        for(int j = 0 ; j < n ; j++)
            if(visited[i][j] == 0 && picture[i][j] != 0){
                int tmp =bfs(i, j, m, n, picture);
                number_of_area++;          
                if(tmp > max_size_of_one_area)
                        max_size_of_one_area = tmp;
            }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}