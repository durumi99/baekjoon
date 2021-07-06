#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string x;
    cin >> x;
    vector <char> v;
    vector <string> vv;
    for(int i = 0 ; i < x.size() ; i++)
        v.push_back(x[i]);
    do{
        string tmp;
		for(int i=0; i < x.size(); i++){
			tmp += v[i];
		}
        vv.push_back(tmp);
	}while(next_permutation(v.begin(),v.end()));
	
	for(int i = 0 ; i < vv.size() -1; i++){
	    if(vv[i] == x){
	        cout << vv[i+1];
	        return 0;
	    }
	}
	cout << 0;
    return 0;
}