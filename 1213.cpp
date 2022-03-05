#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;
string str;
int alpha[30];
void input(){
    cin >> str;
    for(int i = 0 ; i < str.size() ; i++){
        alpha[str[i]-'A']++;
        //cout << str[i]-'A' << '\n';
    }
    // for(int i = 0 ; i < 26 ; i++){
    //     cout << (char)('A'+i) << " " << alpha[i] << '\n';
    // }
}
void solve(){
    int cnt = 0;
    char tmp;
    stack <char> s;
    for(int i = 0 ; i < 26 ; i++){
        if(alpha[i] % 2){
            tmp = (char)('A'+i);
            cnt++;
        }
    }
    if(cnt > 1){
        cout << "I'm Sorry Hansoo" << '\n';
        return;
    }

   for(int i = 0 ; i < 26 ; i++){
        for(int j = 0 ; j < alpha[i] / 2; j++){
            cout << (char)('A'+ i);
            s.push('A'+i);
        }
    }
    if(cnt == 1)
        cout << tmp;
    while(!s.empty()){
        cout << s.top();
        s.pop();
    } 
}
int main() {
    input();
    solve();
    return 0;
}