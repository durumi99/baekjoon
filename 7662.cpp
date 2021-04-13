#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;
int k;
bool visited[1000001];

int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	
	for(int j = 0 ; j < t ; j++){
		cin >> k;
		priority_queue< pair<int,int> > maxH;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minH;
		
		for(int i = 0 ; i < k ; i++){
			char tmpC;
			int tmpN;
			cin >> tmpC >> tmpN;
			
			if(tmpC == 'I'){
				maxH.push({tmpN,i});
				minH.push({tmpN,i});
				visited[i] = true;
			}
			else{
				if(tmpN == 1){ 
					while(!maxH.empty() && !visited[maxH.top().second])
						maxH.pop();
					if(!maxH.empty()){
						visited[maxH.top().second] = false;
            			maxH.pop();
					}
				}
				else{ 
					while(!minH.empty() && !visited[minH.top().second])
						minH.pop();
					if(!minH.empty()){
						visited[minH.top().second] = false;
            			minH.pop();
					}
				}
			}
		}
		while(!maxH.empty() && !visited[maxH.top().second])
			maxH.pop();
		while(!minH.empty() && !visited[minH.top().second])
			minH.pop();	
			
		if(maxH.empty() && minH.empty())
			cout << "EMPTY" << '\n';
		else
			cout << maxH.top().first << ' ' << minH.top().first<< '\n';
	}
	return 0;
}