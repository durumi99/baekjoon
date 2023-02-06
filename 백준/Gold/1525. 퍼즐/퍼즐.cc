#include <iostream>
#include <set>
#include <string>
#include <queue>
#include <utility>

using namespace std;

int map[3][3];
int cnt = -1;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
string start ="";
set <string> s;

bool gameOver(string str){
	if(str == "123456780")
		return true;
	return false;
}

void bfs() {
	queue < pair<string, int> > q;
	q.push({start, 0});
	s.insert(start);
	
	while(!q.empty()) {
		string curStr = q.front().first;
		int curCnt = q.front().second;
		q.pop();
		
		if(gameOver(curStr)){
			cnt = curCnt;
			break;
		}

		int zero = curStr.find('0');
		int curY = zero / 3;
		int curX = zero % 3;
		
		for(int i = 0 ; i < 4 ; i++) {
			int newY = curY + dy[i];
			int newX = curX + dx[i];
			
			if(newY < 0 || newY >= 3 || newX < 0 || newX >= 3)
				continue;
				
			string next = curStr;
			swap(next[zero], next[newY*3 + newX]);
			
			if(s.find(next) == s.end()) {
				s.insert(next);
				q.push({next, curCnt+1});
			}
			
			swap(next[zero], next[newY*3 + newX]);
		}
	}
}
int main() {
	for(int i = 0 ; i < 3 ; i++)
		for(int j = 0 ; j < 3 ; j++) {
			cin >> map[i][j];
			start += map[i][j] +'0';
		}
    
	bfs();

	cout << cnt;
	return 0;
}