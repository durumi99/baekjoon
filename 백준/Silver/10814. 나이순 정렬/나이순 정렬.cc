#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool comp(pair<int,string> a, pair<int, string> b) {
    return a.first < b.first;
}

int main() {
	int n ;
	cin >> n;
    pair< int, string> test = make_pair(1, "asb");
    vector<pair<int, string>> vv;
	int tmp1;
    string tmp2;
    for (int i = 0; i < n; i++) {
    	cin >> tmp1 >> tmp2;
        vv.push_back(make_pair(tmp1,tmp2));
    }

    stable_sort(vv.begin(), vv.end(),comp); 
    for (int i = 0; i < vv.size(); i++) {
        cout << vv[i].first << " " << vv[i].second << "\n";
    }

	return 0;
}