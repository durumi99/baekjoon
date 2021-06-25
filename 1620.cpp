#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin >> n >> m;
	vector <string> v(n+1);
	for(int i = 1 ; i <= n ; i++)
		cin >> v[i];
	vector <pair<string,int>> vv(n+1);
	for(int i = 1 ; i <= n ; i++){
		vv[i].first = v[i];
		vv[i].second = i;
	}
	sort(vv.begin()+1,vv.end());

	for(int i = 0 ; i < m ; i++){
		string input;
		cin >> input;
		if(input[0] >= '0' && input[0] <= '9'){
			cout << v[stoi(input)] << '\n';
		}
		else{
			int left = 1, right = n;
			while(left <= right){
				int mid = (left+right)/ 2;
				
				if(vv[mid].first  == input){
					cout << vv[mid].second << '\n';
					break;
				}
				else if(vv[mid].first < input){
					left = mid + 1;
				}
				else
					right = mid - 1;
			}
		}
		
	}
	return 0;
}