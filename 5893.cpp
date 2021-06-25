#include <iostream>

using namespace std;

int main() {
	string n;
	cin >> n;
	int arr[2][10000];
	int sum[10000];
	for(int i = 0 ; i < 4 ; i++){
		arr[1][i] = 0;
	}
	for(int i = 0 ; i < n.size();i++){
		arr[0][i] = n[n.size()-1-i]-48;
		arr[1][i+4] = n[n.size()-1-i]-48;
	}
	
	for(int i = 0 ; i < n.size()+4;i++){
		sum[i] +=  arr[0][i]+ arr[1][i];
		if(sum[i] > 1){
			sum[i] -=2;
			sum[i+1]++;
		}
	}
	if(sum[n.size()+4] == 1)
		cout << 1;
	for(int i = 0 ; i < n.size()+4;i++){
		cout <<sum[n.size()+3-i];		
	}
	return 0;
}