#include <iostream>
#include <map>
using namespace std;

int main() {
    int tc; cin >> tc;
    map <string,int>::iterator it;
    for(int t = 0 ; t < tc; t++){
        int n,cnt = 1 ; cin >> n;
        string name,type;
        map <string,int> map;
        for(int i = 0 ; i < n ; i++){
            cin >> name >> type;
            if(map.find(type) == map.end())
                map.insert({type,1});
            else
                map[type]++;
        }
        for(it = map.begin() ; it != map.end() ; ++it)
            cnt *= it->second+1;
        cnt -= 1;
        cout << cnt << '\n';
    }
    return 0;
}