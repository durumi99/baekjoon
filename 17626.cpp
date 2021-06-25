#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#define MAX 100000
using namespace std;

int main() {
	int input;
		cin >> input;
	int minNum;
	int dp[50010];
	vector < int > v;
	memset(dp,0,sizeof(dp));
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 1; i < 230; ++i) {
		v.push_back(i * i);
	}
	for (int i = 2; i <= input; i++) {
		minNum = MAX;
 
		for (int j = 0; v[j] <= i; ++j) {
			int tmp = i - v[j];
			minNum = min(minNum, dp[tmp]);
		}
 
		dp[i] = minNum + 1;
	}
	cout << dp[input];
	return 0;
}