#include <iostream>
#include <algorithm>

using namespace std;
 
int main(int argc, char* argv[])
{
	string a,b,num="";
	int carry = 0,tmp;
	cin >> a >> b;
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	while (a.length() < b.length()) {
		a += '0';
	}
	while (a.length() > b.length()) {
		b += '0';
	}
	for(int i = 0 ; i < a.length() ; i++){
		tmp = (a[i]-'0')+(b[i]-'0')+carry;
		if(tmp >= 10){
			carry = 1;
			tmp -= 10;
		}
		else{
			carry = 0;
		}
		num +=  to_string(tmp);
	}
	if (carry == 1)
		num +=  to_string(carry);
	
	reverse(num.begin(),num.end());
	cout << num;
	
	return 0;
}