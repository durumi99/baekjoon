#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int a,b,c,d,e,cnt = 0;
	cin >> a;
	cin >> b;
	cin >> c;
	cin >> d;
	cin >> e;
	if(a < 0){
		cnt += c * (-a);
		cnt += d;
		cnt += b * e;
	}
	else
		cnt += (b-a) * e;
	cout << cnt;
    return 0;
}