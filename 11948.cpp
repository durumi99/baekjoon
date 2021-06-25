#include <iostream>
using namespace std;
int main()
{
	int a,b,c,d,e,f,sum;
	cin >> a;
	cin >> b;
	cin >> c;
	cin >> d;
	cin >> e;
	cin >> f;
	sum = a+b+c+d+e+f;
	sum -= min(a,min(b,min(c,d)));
	sum -= min(e,f);
	cout << sum;
    return 0;
}