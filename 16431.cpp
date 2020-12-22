#include <iostream>
using namespace std;

int main() {
	int Br,Bc,Dr,Dc,Jr,Jc;
	cin >> Br >> Bc;
	cin >> Dr >> Dc; 
	cin >> Jr >> Jc;
	int absBr,absBc,absDr,absDc;
	absBr = abs(Br-Jr);
	absBc = abs(Bc-Jc);
	absDr = abs(Dr-Jr);
	absDc = abs(Dc-Jc);
	int disD,disB;
	disD = absDr+absDc;
	disB = max(absBr,absBc);
	if(disD < disB)
		cout << "daisy";
	else if (disB < disD)
		cout << "bessie";
	else
		cout << "tie";
	return 0;
}