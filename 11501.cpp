#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int T,N,tmp;
	cin >> T;
	for(int tc = 0 ; tc < T; tc++){
		vector <int> v;
		int max = 0;
		long long sum = 0;
		cin >> N;
		for(int i = 0 ; i < N ; i++){
			cin >> tmp;
			v.push_back(tmp);
		}
		reverse(v.begin(),v.end());
		for(int i = 0 ; i < N ; i++){
			if(v[i] > max)
				max = v[i];
			else 
				sum += max - v[i];
		}
		cout << sum << '\n';
	}
	return 0;
}