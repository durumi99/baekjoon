#include <iostream>
using namespace std;

long long f(int n , int r){
	int p =1; 
	int c=1; 
	while(r>0)
	{ 
		c*=n--; 
		p*=r--; 
	}
	return c/p;

}
int main() {
	int n,m,k;
	cin >> n >> m >> k;
	double res = 0.0;
	double p = f(n,m);

	for(int i = k ; i <= m ;i++ ){
		if(n-m < m-i)
			continue;
		double tmp = f(m,i)*f(n-m,m-i);
		res += tmp /p;
	}


	cout.precision(10);
	cout << res << endl;
	return 0;
}