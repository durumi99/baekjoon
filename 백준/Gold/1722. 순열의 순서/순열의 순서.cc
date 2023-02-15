#include <bits/stdc++.h>

using namespace std;

int N;
long long k;
vector <int> v;
set <int> s;
long long calFac(int n) {
	// if(n == 0){
	// 	return 1;
	// }
	long long tmp = 1;
	for(int i = n ; i >= 1 ; i--){
		tmp *= i;
	}
	
	return tmp;
}
void case_1() { // k 입력
	cin >> k;
	int n = N-1;
	k--;
	while(k) {
		long long f = calFac(n);
		long long tmp = k / f;
		cout << v[tmp] << ' ' ;
		v.erase(v.begin()+tmp);
		k %= f;
		n--;
	}
	for(int i = 0 ; i < v.size() ; i++){
		cout << v[i] << ' ';
	}
}

void case_2() { // 수열 입력
	long long ans = 0;
	// int input[N];
	long long tmp = calFac(N-1);
	for(int i = 1 ; i <= N ; i++) {
		int input; cin >> input;
		int idx = find(v.begin(), v.end(), input) - v.begin();
		// cout << idx << ' ' << tmp << '\n';
		ans += idx * tmp;
		if(N-i != 0)
			tmp /= (N-i);
		v.erase(v.begin()+idx);
	}
	// cout << '\n';
	cout << ans+1;
}	// 입력 받아야 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	cin >> N;  
	for(int i = 1 ; i <= N ; i++){
		v.push_back(i);
	}
	
    int tmp; cin >> tmp;
    if(tmp == 1) {
    	case_1();
    } else {
    	case_2();
    }
    return 0;
}