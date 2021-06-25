#include <iostream>
using namespace std;

int main() {
	int n,l,d;
	cin >> n >> l >> d;
	int x=1,intMin = l , intMax = l+4;
	while(true){
		if(d*x >= l*n+5*(n-1)){
			cout << d * x << endl;
			break;
		}
		else if( intMin <= d*x && d*x <= intMax){
			cout << d * x << endl;
			break;
		}
		else if(d*x < intMin){
			x++;
		}
		else {
			intMin += l+5;
			intMax += l+5;
		}
	}
	return 0;
}