#include <iostream>

using namespace std;

int main() {
	int rst[42] = {0};
	int tmp,cnt = 0;
	for(int i = 0; i < 10;i++ ){
		cin >> tmp;
		tmp = tmp % 42;
		rst[tmp]++;
	}
	for(int i = 0 ; i < 42 ; i++)
		if(rst[i] > 0)
			cnt++;
			
	cout << cnt << endl;
	return 0;
}