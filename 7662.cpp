#include <iostream>
#include <map>
using namespace std;

int main() {
    map <int,int>::iterator it;
    int T,k; cin >> T;
    for(int tc = 0 ; tc < T; tc++){
        map <int,int> map;
        cin >> k;
        for(int i = 0 ; i < k; i++){
            char input; cin >> input;
            int tmp; cin >> tmp;
            if(input == 'D' && !map.empty()){
                if(tmp == -1){
                    if(map.begin()->second == 1)
                        map.erase(map.begin());
                    else
                        map.begin()->second--;
                }
                else if(tmp == 1){
                    if((--map.end())->second == 1)
                        map.erase((--map.end()));
                    else
                        (--map.end())->second--;
                }
            }
            else if(input == 'I'){
                if(map.find(tmp) == map.end())
                    map.insert({tmp,1});
                else
                    map[tmp]++;
            }
        }
        if(map.empty()){
            cout << "EMPTY\n";
        }
        else {
            cout << (--map.end())->first << ' ' << map.begin()->first <<'\n';
        }
    }
    return 0;
}