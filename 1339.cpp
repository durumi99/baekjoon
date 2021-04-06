#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;


int main() {
	int n,answer = 0,max=9;
	cin >> n;
	int alphabet[26] = {0};
	string s;
	for(int i=0;i<n;i++){
		cin>>s;
        for(int j=0;j<s.length();j++){
            alphabet[s[j]-65]+=(int)pow(10,s.length()-j-1);
       	}
    }
    vector<int> v;
    for(int i=0;i<26;i++){
        if(alphabet[i]){
            v.push_back(alphabet[i]);
        }
    }
    sort(v.begin(),v.end(),greater<int>());
    for(int i = 0 ; i < v.size(); i++)
    	answer += v[i]*(max--);
    	
    cout << answer;
	return 0;
}