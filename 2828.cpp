#include <iostream>
using namespace std;

int main() {
	int n,m,j,apple,ans = 0;
	cin >> n >> m;
	cin >> j;
	int loc = m;
	for(int i = 0 ; i < j ; i++){
		cin >> apple;
		if(apple > loc){
			ans += apple-loc;
			loc = apple;
		}
		else if(apple < loc-m+1){
			ans += loc-m+1-apple;
			loc = apple+m-1;
		}
	}
	cout << ans;
	return 0;
}