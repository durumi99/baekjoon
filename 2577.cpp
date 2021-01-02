
#include <iostream>
using namespace std;

int main() {
	int a,b,c,tmp;
	int arr[10]= {0};
	cin >> a >> b >> c;
	int res = a*b*c;
	while(res){
		tmp = res % 10;
		arr[tmp]++;
		res /= 10;
	}
	for(int i = 0 ; i < 10 ;i++)
		cout << arr[i] << endl;
	return 0;
}