#include <iostream>
using namespace std;
int cnt = 0;
int month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

bool isYoon(int year){
	if(year % 400 == 0)
		return true;
	else if(year % 100 == 0)
		return false;
	else if(year % 4 == 0)
		return true;
	else
		return false;
}

int days(int y, int m, int d) {
	int r = 0;
	for (int i = 0; i < y; ++i) {
		r += 365 + isYoon(i);
	}
	for (int i = 0; i + 1 < m; ++i) {
		if (i == 1) r += isYoon(y);
		r += month[i];
	}
	return r + d;
}
int main() {
	int today[3];
	int dday[3];
	cin >> today[0] >> today[1] >> today[2];
	cin >> dday[0] >> dday[1] >> dday[2];
	if(dday[0] - today[0] >= 1000 && dday[1] >= today[1] && dday[2] >= today[2]){
		cout << "gg" << endl;
		return 0;
	}
	int td = days(today[0],today[1],today[2]);
	int dd = days(dday[0],dday[1],dday[2]);
	
	cout << "D-" << dd -td << endl;
	return 0;
}