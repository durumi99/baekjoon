#include <iostream>
#include <map>
using namespace std;

int main() {
    map <string,int> tree;
    map <string,int>::iterator it;
    int cnt = 0;
    string tmp;
    while(getline(cin,tmp)){
        cnt ++;
        if(tree.find(tmp) == tree.end())
            tree.insert({tmp,1});
        else
            tree[tmp]++;
    }
    for(it = tree.begin(); it != tree.end() ; ++it){
        cout << fixed; 
        cout.precision(4);
        cout << it->first << ' ' << (float)it->second / cnt * 100 << '\n';
    }
    return 0;
}