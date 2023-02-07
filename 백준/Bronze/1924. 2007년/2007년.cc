#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	
	int x, y; cin >> x >> y;
	string dayoftheWeek[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
	int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int days = 0;
	for(int i = 1 ; i < x ; i++) {
	    days += month[i];
	}
	days += y;
	days %= 7;
	cout << dayoftheWeek[days];
	return 0;
}