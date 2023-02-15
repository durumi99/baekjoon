#include <bits/stdc++.h>

using namespace std;

int N;
long long k;
vector <int> v;
set <int> s;
long long f[21];

void setFac(int n) {
	f[0] = 1;
	for(int i = 1 ; i <= n ; i++){
		f[i] = f[i-1] * i;
	}
}

void case_1() { // k 입력
	cin >> k;
	int n = N-1;
	
	k--;
	while(k) {
		long long tmp = k / f[n];
		cout << v[tmp] << ' ' ;
		v.erase(v.begin()+tmp);
		k %= f[n];
		n--;
	}
	for(int i = 0 ; i < v.size() ; i++){
		cout << v[i] << ' ';
	}
}

void case_2() { // 수열 입력
	long long ans = 0;
	
	for(int i = 1 ; i <= N ; i++) {
		int input; cin >> input;
		int idx = find(v.begin(), v.end(), input) - v.begin();
		ans += idx * f[N-i];
		
		v.erase(v.begin()+idx);
	}
	cout << ans+1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	cin >> N;  
	for(int i = 1 ; i <= N ; i++){
		v.push_back(i);
	}
	setFac(N);
	
    int tmp; cin >> tmp;
    if(tmp == 1) {
    	case_1();
    } else {
    	case_2();
    }
    return 0;
}