#include <iostream>
#include <map>
using namespace std;

int main() {
    int a, b,tmp,cnt = 0;    cin >> a >> b;
    map <int,int> aa;
    for(int i = 0 ; i < a ; i++){
        cin >> tmp;
        aa.insert({tmp,i});
    }
    for(int i = 0 ; i < b ; i++){
        cin >> tmp;
        if(aa.find(tmp) != aa.end())
            cnt++;
    }
    
    cout << a+b - 2*cnt ;
    return 0;
}