#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n,tmp1,tmp2;
	cin >> n;
	pair <int,int> p[n];
	int cnt[n];
	vector<pair<int, int>> vv;
	for (int i = 0; i < n; i++) {
    	cin >> tmp1 >> tmp2;
        vv.push_back(make_pair(tmp1,tmp2));
        cnt[i] = 1;
    }
    
  	for (int i = 0; i < n; i++) 
  		for (int j = 0; j < n; j++) {
  			if(i == j)
  				continue;
  			if(vv[i].first > vv[j].first && vv[i].second > vv[j].second)
  				cnt[j]++;
  		}
  	
	for (int i = 0; i < n; i++)
		cout << cnt[i] << ' ';
	return 0;
}