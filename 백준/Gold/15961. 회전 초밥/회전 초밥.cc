#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, d, k ,c;
    cin >> N >> d >> k >> c;
    int sushi[N];
    
    for(int i = 0 ; i < N ; i++) {
    	cin >> sushi[i];
    }
    
    int maxSushi = 0;
    int left = 0;
    int right = k-1;
    unordered_map<int, int> m;
    
    for(int i = left ; i < right ; i++) {
    	m[sushi[i]]++;
    }
    
    while(left < N) {
    	m[sushi[right]]++;
    	int num = m.size();
    	if(m.find(c) == m.end()) {
    		maxSushi = max(maxSushi, num+1);
    	} else {
    		maxSushi = max(maxSushi, num);
    	}
    	m[sushi[left]]--;
    	if(m[sushi[left]] == 0)
    		m.erase(m.find(sushi[left]));
	    left++;
	    right = (right+1) % N;
    }
    
    cout << maxSushi;
    return 0;
}