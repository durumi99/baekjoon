#include <iostream>
using namespace std;

int main() {
	int db[11]= {0};
	db[1] = 1;
	db[2] = 2;
	db[3] = 4;
	for(int i = 4 ; i <= 10 ; i++)
		db[i] = db[i-1] + db[i-2] + db[i-3];

	int tc,n;
	cin >> tc;
	
	for(int i = 0 ; i < tc ; i++){
		cin >> n;
		cout << db[n] << '\n';
	}
	
	return 0;
}