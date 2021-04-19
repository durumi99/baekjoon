#include <iostream>
#include <queue>
#include <utility>
#include <cmath>
using namespace std;

int main() {
	int n;
	cin >> n;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	for(int i = 0 ; i < n ; i++){
		int tmp;
		cin >> tmp;
		if(tmp != 0) // push
			pq.push( make_pair(abs(tmp),tmp) );
		else if(!pq.empty()){ // pop
			cout << pq.top().second << '\n';
			pq.pop();
		}
		else
			cout << 0 << '\n';
			
	} 
	return 0;
}