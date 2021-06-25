#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;

int main() {
	int tc;
	cin >> tc;
	bool visited[10000];
	for(int t = 0 ; t < tc ; t++){
		int a,b;
		cin >> a >> b;
		queue <pair<int,string> > q;
		memset(visited,false,sizeof(visited));
		q.push(make_pair(a,""));
		while(!q.empty()){
			int tmpN = q.front().first;
			string tmpS = q.front().second;
			if(tmpN == b){
				cout << tmpS << '\n';
				break;
			}
			q.pop();
			// CaseD
			int CaseD = 2*tmpN % 10000;
			if(!visited[CaseD]){
				visited[CaseD] = true;
				q.push(make_pair(CaseD,tmpS+"D"));
			}
			// CaseS
			int CaseS = tmpN-1;
			if(CaseS == -1)
				CaseS = 9999;
			if(!visited[CaseS]){
				visited[CaseS] = true;
				q.push(make_pair(CaseS,tmpS+"S"));
			}
			//CaseL,CaseR
			int d1 = tmpN / 1000;
			int CaseL = d1 + tmpN % 1000 * 10;
			if(!visited[CaseL]){
				visited[CaseL] = true;
				q.push(make_pair(CaseL,tmpS+"L"));
			}
			int d4 = tmpN % 10;
			int CaseR = d4*1000 + tmpN / 10;
			if(!visited[CaseR]){
				visited[CaseR] = true;
				q.push(make_pair(CaseR,tmpS+"R"));
			}
		}
	}
	return 0;
}