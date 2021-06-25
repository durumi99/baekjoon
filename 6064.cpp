#include<iostream>
#include<algorithm>

using namespace std;

int gcd(int a,int b){
	if(a % b == 0)
		return b;
	return gcd(b,a % b);
}

int lcm(int a, int b){
	return (a * b) / gcd(a,b);
}

int main(){
	int tc;
	cin >> tc;
	int m,n,x,y;
	for(int i = 0 ; i <  tc ; i++){
		cin >> m >> n >> x >> y;
		int max = lcm(m,n);
		
		while(true){
			if(x > max || (x-1) % n + 1 ==y)
				break;
			x += m;
		}
		if(x > max)
			cout << -1 << '\n';
		else
			cout << x << '\n';
	}
}