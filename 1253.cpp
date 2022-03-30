#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <long long> v;
int n,ans = 0;

void isGood(int cur){
    int start = 0 ; 
    int end = n - 1;
    while(start < end){
        if(v[start] + v[end] == v[cur]){
        	if(start != cur && end != cur){
            	ans++;
            	break;
        	}
        	else if(start == cur)
        		start++;
        	else if(end == cur)
        		end--;
        }
        else if(v[start] + v[end] < v[cur]){
            start++;
        }
        else{
            end--;
        }
    }
}
void input(){
    long long tmp;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(),v.end());
}
void solve(){
    for(int i = 0 ; i < n ; i++){
        isGood(i);
    }
    cout << ans << '\n';
}
int main() {
    input();
    solve();
    return 0;
}