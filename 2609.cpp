#include <iostream>
using namespace std;

int main() {
	int n,m;
	cin >> n >> m;
	int tmpN = n, tmpM = m,r;
	while(true){
		r = tmpN % tmpM;
		if(r == 0)
			break;
		else{
			tmpN = tmpM;
			tmpM = r;
		}	
	}
	cout << tmpM << '\n';
	cout << n*m/tmpM << '\n';
	return 0;
}