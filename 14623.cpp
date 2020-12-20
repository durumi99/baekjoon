#include <iostream>
using namespace std;
int main()
{
	string a,b;
	int tmpA[30],tmpB[30],sum[100] = {};
	cin >> a;
	cin >> b;
	for(int i = 0 ; i < a.size(); i++)
		tmpA[i] =a[a.size()-1-i]-48;
	
	for(int i = 0 ; i < b.size(); i++){
		tmpB[i] =b[b.size()-1-i]-48;
		if(tmpB[i] == 1){
			for(int j = 0 ; j < a.size(); j++){
				sum[i+j] += tmpA[j];
			}
		}
	}
	
	for(int i = 0 ; i < 100;i++){
		while(sum[i] > 1){
			sum[i]-=2;
			sum[i+1]++;
		}
	}
	
	if(sum[a.size()+b.size()-1])
		cout << 1;
	for(int i = a.size()+b.size()-2 ; i >= 0 ; i--){
		cout <<sum[i];		
	}
	
    return 0;
}