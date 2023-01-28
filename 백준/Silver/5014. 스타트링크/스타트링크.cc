#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

int F, S, G, U, D; 
int visited[1000001];
int minCnt = -1;


int main(int argc, char *argv[]) {
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> F >> S >> G >> U >> D;
    
    visited[S] = 1;
    queue < pair <int, int> > q;
    q.push({S, 0});
    
    while(!q.empty()) {
    	int curFloor = q.front().first;
    	int curCnt = q.front().second;
    	q.pop();
    	if(curFloor == G) {
    		minCnt = curCnt;
    		break;
    	}
    	
    	if(curFloor + U <= F && !visited[curFloor + U]) {
    		visited[curFloor + U] = 1;
    		q.push({curFloor + U, curCnt + 1});
    	}
    	
    	if(curFloor - D >= 1 && !visited[curFloor - D]) {
    		visited[curFloor - D] = 1;
    		q.push({curFloor - D, curCnt + 1});
    	}
    }
    if(minCnt == -1){
    	cout << "use the stairs";
    } else {
    	cout << minCnt;
    }
	return 0;
}