#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,sum = 0;
	cin >> n;
	int arr[n];
	int cnt_num[10000] = {0};
	int mode_cnt = 0, mode_num;
	vector <int> mode;
	for(int i = 0 ; i < n ; i++){
		cin >> arr[i];
		sum += arr[i];
		int idx  = arr[i] < 0 ? 8001+arr[i] :arr[i];
		cnt_num[idx]++;
		if(mode_cnt < cnt_num[idx]){
			mode_cnt = cnt_num[idx];
			mode.clear();
			mode.push_back(arr[i]);
		}
		else if(mode_cnt == cnt_num[idx]){
			mode.push_back(arr[i]);
		}
	}
	
	sort(arr,arr+n);
	sum = round( (double)sum / n);
	int mid = arr[n/2];
	int range = arr[n-1] - arr[0];
	
	cout << sum << '\n';
	cout << mid << '\n';
	if(mode.size() == 1)
		cout << mode[0] << '\n';
	else{
		sort(mode.begin(),mode.end());
		cout << mode[1] << '\n';
	}
	cout << range << '\n';
	return 0;
}