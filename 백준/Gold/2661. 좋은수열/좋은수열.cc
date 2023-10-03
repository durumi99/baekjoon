#include <bits/stdc++.h>

using namespace std;
int n;
bool check = false;

bool isGood(string str) {
    for(int i = 1 ; i <= str.length() / 2 ; i++) {
        for(int j = 0 ; j < str.length() - i ; j++) {
            string a = str.substr(j, i);
            string b = str.substr(j + i , i);
            // cout << str << '\n' << a << ' ' << b << '\n';
            if(a == b) {
                return false;
            }
        }
    }
    
    return true;
}
void dfs(int idx, string str) {
    if(check)
        return;
    if(idx == n) {
        check = true;
        cout << str;
        return;
    }
    
    for(char i = '1' ; i <= '3' ; i++) {
        if(isGood(str+i)) {
            dfs(idx+1, str+i);
        }
    }
}
int main() {
    cin >> n;
    string str = "";
    dfs(0, str);
    return 0;
}