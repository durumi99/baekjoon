#include <bits/stdc++.h>

#define MAX 111
using namespace std;

int K;
int visited[10];
vector <char> v;
string maxS="", minS="";
void makeMaxString(int idx, vector <int> num) {
	if(maxS != "")
		return;
	if(idx == K+1) {
		string tmp = "";
		for(int i = 0 ; i < K + 1 ; i ++) {
			tmp += to_string(num[i]);
		}
		// maxS = max(maxS, tmp);
		maxS = tmp;
		return;
	}
	for(int i = 9 ; i >= 0 ; i--) {
		if(visited[i])
			continue;
		if(idx == 0) {
			visited[i] = 1;
			num.push_back(i);
			makeMaxString(idx+1, num);
			visited[i] = 0;
			num.pop_back();
		} else {
			if(v[idx-1] == '<') {
				if(num[idx-1] >= i)
					continue;
			} else {
				if(num[idx-1] <= i)
					continue;
			}
			visited[i] = 1;
			num.push_back(i);
			makeMaxString(idx+1, num);
			visited[i] = 0;
			num.pop_back();
		}
	}
}

void makeMinString(int idx, vector <int> num) {
	if(minS != "")
		return;
	if(idx == K+1) {
		string tmp = "";
		for(int i = 0 ; i < K + 1 ; i ++) {
			tmp += to_string(num[i]);
		}
		// cout << tmp << '\n';
		// if(minS == "")
		// 	minS = tmp;
		// else
		// 	minS = min(minS, tmp);
		minS = tmp;
		return;
	}
	for(int i = 0 ; i < 10 ; i++) {
		if(visited[i])
			continue;
		if(idx == 0) {
			visited[i] = 1;
			num.push_back(i);
			makeMinString(idx+1, num);
			visited[i] = 0;
			num.pop_back();
		} else {
			if(v[idx-1] == '<') {
				if(num[idx-1] >= i)
					continue;
			} else {
				if(num[idx-1] <= i)
					continue;
			}
			visited[i] = 1;
			num.push_back(i);
			makeMinString(idx+1, num);
			visited[i] = 0;
			num.pop_back();
		}
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >>  K;
    for(int i = 0 ; i < K ; i++) {
    	char tmp; cin >> tmp;
    	v.push_back(tmp);
    }
    vector <int> tmp;
	makeMaxString(0, tmp);
	tmp.clear();
	for(int i = 0 ; i < 9 ; i++)
		visited[i] = 0;
	makeMinString(0, tmp);
	cout << maxS << '\n' << minS;	
    return 0;
}