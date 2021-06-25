#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int N,r,c,cnt = 0;
void rec(int x,int y,int len){
	
	if(x == r && y == c){
		cout << cnt << '\n';
		exit(0);
	}
	if(len == 1){
		cnt++;
		return;
	}
	if(!(x<=r && r<x+len && y<=c && c<y+len)){
        cnt += len*len;
        return;
    }

    rec(x,y,len/2);
    rec(x,y+len/2,len/2);
    rec(x+len/2,y,len/2);
    rec(x+len/2,y+len/2,len/2);

}
int main() {
	cin >> N >> r >> c;
	rec(0,0,pow(2,N));
	return 0;
}