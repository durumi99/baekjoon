#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) 
    	return a.first < b.first;
    return a.second < b.second;
}

int main() {
	int n ;
	cin >> n;
    pair< int, int> test = make_pair(1, 2);
    vector<pair<int, int>> vv;
	int tmp1,tmp2;
    
    for (int i = 0; i < n; i++) {
    	cin >> tmp1 >> tmp2;
        vv.push_back(make_pair(tmp1,tmp2));
    }

    sort(vv.begin(), vv.end(), comp); 
    for (int i = 0; i < vv.size(); i++) {
        cout << vv[i].first << " " << vv[i].second << "\n";
    }

	return 0;
}