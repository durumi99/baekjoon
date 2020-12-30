#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {
	int n,cnt=0;
	char tmp;
	cin >> n ;
	string player[n];
	for(int i = 0 ; i < n ; i++)
		cin >> player[i];
	sort(player,player+n);
	cnt = 1;
	for(int i = 1 ; i < n ; i++){
		if(player[i][0] == player[i-1][0]){
			cnt++;
		}
		else {
			cnt = 1;
		}
		if(cnt >=5 && tmp != player[i][0]){
			cout << player[i][0];
			tmp = player[i][0];
		}
	}
	if(tmp == NULL)
		cout << "PREDAJA" << endl;
	return 0;
}