#include <iostream>
#include <vector>

using namespace std;
string db[50];
vector <char> acint= {'a','c','i','n','t'};
int visited[26] = {0};
int n,k,res;
void f(int alpha, int cnt){
	if(cnt == k){
		int tmp = 0;
		for( int i = 0 ; i < n ; i++){
			bool flag = true;
			for( int j = 0 ; j < db[i].length(); j++){
				if ( !visited[db[i][j]- 'a']){
					flag = false;
					break;
				}
			}
			if(flag)
				tmp++;
		}
		res = max(res,tmp);
		return;
	}
	
	for( int c = alpha ; c < 26 ; c++){
		if(!visited[c]){
			visited[c] = true;
			f(c,cnt+1);
			visited[c] = false;
		}
	}
}
int main() {
	cin >> n >> k;
	if(k < 5){
		cout << 0;
		return 0;
	}
	else if ( k == 26){
		cout << n;
		return 0;
	}
	k -= 5;
	for(int i = 0 ; i < 5 ; i++){
		visited[acint[i]-'a'] = 1;
	}
	string tmp;
	for(int i = 0 ; i < n ; i++){
		cin >> tmp;
		for(int j = 4; j < tmp.length() - 4 ; j++){
			if(tmp[j] != 'a' && tmp[j] != 'c' && tmp[j] != 'i' && tmp[j] != 'n' && tmp[j] != 't')
				db[i].push_back(tmp[j]);
		}
	}
		
	f(0,0);
	cout << res;
	return 0;
}