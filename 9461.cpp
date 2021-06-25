#include <iostream>
using namespace std;

int main() {
	long long int p[101];
	p[1]=p[2]=p[3]=1;
	p[4]=p[5]=2;
	for(int i = 6 ; i <= 100 ; i++)
		p[i] = p[i-1] + p[i-5];
		
	int tc;	
	cin >> tc;
	for(int t = 0 ; t < tc ; t++){
		int n;
		cin >> n;
		cout << p[n] << '\n';
	}
	return 0;
}