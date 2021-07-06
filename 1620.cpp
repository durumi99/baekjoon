#include <iostream>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    map <string,int>  v;
    map<string,int>::iterator it;
    string ary[101010];
    int n,m;
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
        string tmp;
        cin >> tmp;
        v.insert({tmp,i+1});
        ary[i+1] = tmp;
    }
    for(int i = 0 ; i < m ; i++){
        string tmp;
        cin >> tmp;
        if(tmp[0] >= '0' && tmp[0] <= '9')
			cout << ary[stoi(tmp)] << '\n';
		else
		    cout << v.find(tmp)->second << '\n';
        }
    return 0;
}