#include <iostream>
using namespace std;

int main() {
	int n,tmp,ySum=0,mSum=0;
	cin >> n;
	for(int i = 0 ; i < n ; i++){
		cin >> tmp;
		ySum += ( tmp / 30 + 1 ) * 10;
		mSum += ( tmp / 60 + 1 ) * 15;
	}
	if(ySum > mSum)
		cout << 'M' << " " << mSum << endl;
	else if(mSum > ySum)
		cout << 'Y' << " " << ySum << endl;
	else
		cout << 'Y' << " " << 'M' << " " << mSum << endl;
	return 0;
}