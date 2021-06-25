#include <iostream>
#include <string>
using namespace std;

int main() {
	int cnt=0,spaceCnt=0;
	string tmp;
	getline(cin,tmp);
	cin >> tmp;

	for(int i = 0; i < tmp.size();i++){
		if(tmp[i] == ' ')
			spaceCnt++;
	}
	cnt = spaceCnt +1;
	if(spaceCnt == tmp.size()){
		cout << 0;
		return 0;
	}
	else {
		if(tmp[0] == ' ')
			cnt--;
		if(tmp[tmp.size()-1] == ' ')
			cnt--;
	}
	cout << cnt ;
	return 0;
}