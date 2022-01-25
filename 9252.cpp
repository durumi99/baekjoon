#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector <char> v1(1001),v2(1001);
stack <char> s;
string str1,str2;
int dp[1001][1001];

void LCS(){
    for(int i = 0 ; i <= str1.size() ; i++)
        for(int j = 0 ; j <= str2.size() ; j++){
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if(v1[i] == v2[j]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    return;
}
void input(){
    cin >> str1 >> str2;
    for(int i = 0 ; i < str1.size(); i++){
        v1[i+1] = str1[i];
    }
    for(int i = 0 ; i < str2.size(); i++){
        v2[i+1] = str2[i];
    }
}
void output(){
    cout << dp[str1.size()][str2.size()] << '\n';
    int tmp = dp[str1.size()][str2.size()];
    int x = str1.size();
    int y = str2.size();
    while(tmp){
        if(dp[x-1][y] == dp[x][y])
            x--;
        else if(dp[x][y-1] == dp[x][y])
            y--;
        else{
            s.push(v1[x]);
            x--;
            y--;
            tmp--;
        }
    }
    while(!s.empty()){
        cout << s.top();
        s.pop();
    }
}
int main() {
    input();
    LCS();
    output();
    
    return 0;
}