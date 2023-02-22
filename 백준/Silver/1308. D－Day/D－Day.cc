#include <bits/stdc++.h>

using namespace std;
int N;
int date[2][3];
int month[12] = {31, 28, 31, 30, 31 ,30 ,31, 31, 30, 31, 30, 31};

bool isLeapYear(int year) {
	if(year % 4 == 0) 
		if (year % 100 != 0 || year % 400 == 0)
			return true;
	
	return false;
}
int getWholeDay(int curDate[3]){
	int tmp = 0;
	
	for(int i = 0 ; i < curDate[0] ; i++) {
		if(isLeapYear(i)) {
			tmp++;
		}
		tmp += 365;
	}
	for(int i = 0 ; i < curDate[1]-1 ; i++)
		tmp += month[i];
		
	tmp += curDate[2];
	
	return tmp;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	for(int i = 0 ; i < 2 ; i++) 
		for(int j = 0 ; j < 3 ; j++)
			cin >> date[i][j];
			
	if(date[1][0] > date[0][0] + 1000) {
		cout << "gg";
		return 0;
	}
	if(date[1][0] == date[0][0] + 1000) {
		if(date[1][1] > date[0][1]) {
			cout << "gg";
			return 0;
		}
		if(date[1][1] == date[0][1]) {
			if(date[1][2] >= date[0][2]) {
				cout << "gg";
				return 0;
			}
		}
		
	}
	int cur = getWholeDay(date[0]);
	int day = getWholeDay(date[1]);
	
	if(isLeapYear(date[0][0]) && date[0][1] >= 3)
		cur++;
	
	if(isLeapYear(date[1][0]) && date[1][1] >= 3)
		day++;
		
	cout << "D-" << day-cur;
    return 0;
}