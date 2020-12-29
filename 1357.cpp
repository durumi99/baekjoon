#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <string>
using namespace std;

int multi(){
	
}
int main() {
	string x,y;
	cin >> x >> y;
	
	reverse(x.begin(),x.end());
	reverse(y.begin(),y.end());
	
	int intX = atoi(x.c_str());
	int intY = atoi(y.c_str());
	int sum = intX+intY;
	
	string res = to_string(sum);
	reverse(res.begin(),res.end());
	int intR = atoi(res.c_str());
	cout << intR << endl;
	return 0;
}