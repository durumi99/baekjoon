#include <iostream>
#include <string>
using namespace std;

int main() {
    int cnt = 0;
    string s,tmp;
    getline(cin,s);
    getline(cin,tmp);
    if(s.length() < tmp.length()){
        cout << 0;
        return 0;
    }
    for(int i  = 0 ; i < s.length(); i++){
        bool check = true;
        for(int j = 0 ; j < tmp.length() ; j++){
           if(s[i+j] != tmp[j]){
               check = false;
               break;
           }
        }
        if(check == true){
            cnt++;
            i += tmp.length()-1;
        }
    }
    cout << cnt;
    return 0;
}