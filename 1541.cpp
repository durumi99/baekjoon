#include <iostream>
#include <string>
using namespace std;

int minR(string str){
	int res = 0;
	string temp = "";
	bool minus = false;
	for(int i = 0 ; i <= str.length();i++){
		if(str[i] == '+' || str[i] == '-' || str[i] == '\0'){
			if(minus)
				res -= stoi(temp);
			else
				res += stoi(temp);
			temp = "";
			if(str[i] == '-')
				minus = true;
			continue;
		}
		temp += str[i];
	}
	return res;
}
int main() {
	string str;
	cin >> str;
	cout << minR(str) << endl;
	return 0;
}