#include <iostream>
#include <string>
using namespace std;

int main() {
    string word, bomb ; cin >> word >> bomb;
    string ans = "";
    for(int i = 0 ; i < word.length() ; i++){
        int bombL = bomb.length()-1;
        ans += word[i];
        if(word[i] == bomb[bombL]){
            if(ans.length() >= bomb.length()){
                bool check = true;
                int ansL = ans.length()-1;
                while(bombL>0){
                    if(bomb[--bombL] != ans[--ansL]){
                        check = false;
                        break;
                    }
                }
                if(check){
                    for(int j = 0 ; j < bomb.length(); j++)
                        ans.pop_back();
                }
            }
        }
    }
    if(ans.size() == 0)
        cout << "FRULA";
    else
        cout << ans;
    return 0;
}