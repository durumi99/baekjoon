#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<pair<int,int>>v;
    priority_queue<int,vector<int>,greater<int>> pq;
    
    for(int i=0;i<n;i++){
    	int start,end;
        cin >> start >> end;
        v.push_back(make_pair(start,end));
    }
	sort(v.begin(),v.end());
    pq.push(v[0].second);
    
    for(int i = 1 ; i < v.size();i++){
    	if(pq.top() <= v[i].first)
    		pq.pop();
    	pq.push(v[i].second);
    }
    cout << pq.size() << '\n';
	return 0;
}