#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 10101
using namespace std;
int n;
int x[MAX];
int y[MAX];
double p(int v1,int v2,int v3){
    double x1 = x[v1];
    double x2 = x[v2];
    double x3 = x[v3];
    double y1 = y[v1];
    double y2 = y[v2];
    double y3 = y[v3];
    
    double tmp1 = x1 * y2 + x2 * y3 + x3 * y1;
	double tmp2 = x2 * y1 + x3 * y2 + x1 * y3;

	double result = tmp1 - tmp2;
	return result / 2;
}
void f(){
    double sum = 0;
    for(int i = 1 ; i < n-1 ; i++)
        sum += p(0,i,i+1);
        
    cout << fixed;
	cout.precision(1);
	cout << abs(sum) << '\n';
}
void input(){
    cin >> n ;
    for(int i = 0 ; i < n ; i++)
        cin >> x[i] >> y[i];
}
int main() {
    input();
    f();
    return 0;
}