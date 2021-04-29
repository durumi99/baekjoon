#include <iostream>
using namespace std;
int f(int a,int b,int c){
	if(b == 0)
		return 1;

	int n = f(a,b/2,c);
	int res = 1LL * n * n % c;
	if(b % 2)
		res = 1LL * res * a % c;
	return res;
}
int main() {
    int a,b,c;
    int ans;
    cin >> a >> b >> c;
	ans = f(a,b,c);
    cout << ans;
    return 0;
}