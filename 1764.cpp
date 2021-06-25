#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector <string> vN;
vector <string> vM;
vector <string> v;
int cnt = 0;
bool Bsearch(int len,string target){
	int mid,left = 0, right = len-1;
	while(left <= right){
		mid = (left+right)/2;
		if(vN[mid] == target){
			cnt++;
			return true;
		}
		else if (vN[mid] > target)
			right = mid -1;
		else 
			left = mid + 1;
	}
	return false;
}
int main() {
	int N,M;
	string tmp;
	cin >> N >> M;
	
	for(int i = 0 ; i < N ; i++){
		cin >> tmp;
		vN.push_back(tmp);
	}
	sort(vN.begin(),vN.end());
	
	for(int i = 0 ; i < M ; i++){
		cin >> tmp;
		vM.push_back(tmp);
	}
	sort(vM.begin(),vM.end());
	
	for(int i = 0 ; i < M ; i++)
		if(Bsearch(N,vM[i]))
			v.push_back(vM[i]);
	
	cout << cnt << '\n';
	for(int i = 0 ; i < v.size();i++)
		cout << v[i] << '\n';
	return 0;
}