#include <iostream>
#include <stack>
#include <vector>

#define MAX 1000001
using namespace std;
int n;
vector <int> v(MAX);
stack <int> s;
void input(){
    cin >> n ;
    for(int i = 0 ; i < n ; i++){
        cin >> v[i];
    }
}
void solve(){
    vector <int> ans(n,-1);
    
    for(int i = 0 ; i < n ; i++){
        while(!s.empty() && v[s.top()] < v[i]){
            ans[s.top()] = v[i];
            s.pop();
        }
        s.push(i);
    }
    
    for(int i = 0 ; i < n ; i++)
        cout << ans[i] << ' ';
}
int main() {
    input();
    solve();
    return 0;
}