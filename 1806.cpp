#include <iostream>
#include <algorithm>
#define MAX 101010
using namespace std;

int n,s;
int g[MAX];
int sum(int start,int end){
    int res = 0;
    for(int i = start ; i <= end ; i++)
        res += g[i];
    return res;
}
void twoP(){
    int start = 0 ,end = 0;
    int tmp, ans = 99999999;
    int sum = 0;
    while(start <= end){
        if(sum >= s){
            ans = min(ans,end-start);
            sum -= g[start++];
        }
        else if(end == n)
            break;
        else 
            sum += g[end++];
    }
    if(ans == 99999999)
        cout << 0 << '\n';
    else
        cout << ans << '\n';
}
void input(){
    cin >> n >> s;
    for(int i = 0 ; i < n ;i++)
        cin >> g[i];
}
int main() {
    input();
    twoP();
    return 0;
}