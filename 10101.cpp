#include <iostream>
using namespace std;

int main() {
	int a[3];
	for(int i = 0 ; i < 3 ; i++)
		cin >>a[i];
	if((a[0]+a[1]+a[2]) != 180)
		cout << "Error";
	else if(a[0] == a[1] && a[0] == 60)
		cout << "Equilateral";
	else if((a[0] == a[1] && a[0] != 60) ||	(a[0] == a[2] && a[0] != 60) || (a[1] == a[2] && a[0] != 60))
		cout << "Isosceles";
	else 
		cout << "Scalene";
	return 0;
}