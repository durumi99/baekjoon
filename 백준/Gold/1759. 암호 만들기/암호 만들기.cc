#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

int L, C; 
int visited[1000001];
vector <char> vowel;
char letter[15];
void bt(int idx, int vowelCnt, int consonantCnt, string s) {
	// cout << s << '\n';
	if(s.length() == L){
		if(vowelCnt >= 1 && consonantCnt >= 2) {
			cout << s << '\n';
		}
		return;
	}
	if(idx == C) {
		return;
	}
	if(find(vowel.begin(), vowel.end(), letter[idx]) == vowel.end()) {
		bt(idx+1, vowelCnt, consonantCnt+1, s+letter[idx]);
	} else {
		bt(idx+1, vowelCnt+1, consonantCnt, s+letter[idx]);
	}
	
	bt(idx+1, vowelCnt, consonantCnt, s);
}

int main(int argc, char *argv[]) {
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> L >> C;
    for(int i = 0 ; i < C ; i++) {
    	cin >> letter[i];
    	if(letter[i] == 'a' || letter[i] == 'e' || letter[i] == 'i' || letter[i] == 'o' || letter[i] == 'u')
    		vowel.push_back(letter[i]);
    }
    sort(letter, letter+C);
    bt(0, 0, 0, "");
	return 0;
}