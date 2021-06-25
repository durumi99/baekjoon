
#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string alphabet= "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int cnt[26] = {0};
	string input;
	cin >> input;
	for(int i = 0 ; i < input.size();i++){
		for(int j = 0 ; j < 26 ; j++){
			if(input[i] == alphabet[j] || input[i]-32 == alphabet[j])
				cnt[j]++;
		}
	}
	int max = 0,tmp;
	bool same;
	for(int i = 0 ; i < 26 ; i++){
		if(cnt[i] > max){
			max = cnt[i];
			tmp = i;
			same = false;
		}
		else if(cnt[i] == max){
			same = true;
		}
	}
	if(same)
		cout << '?' << '\n';
	else
		cout << alphabet[tmp] << '\n';
	return 0;
}