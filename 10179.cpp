#include <iostream>
using namespace std;

int main() {
	int tc;
	cin >> tc;
	double n[tc];
	for(int i = 0 ; i < tc ;i++){
		cin >> n[i];
		n[i] *= 0.8;
		printf("$%.2f\n",n[i]);
	}
	return 0;
}