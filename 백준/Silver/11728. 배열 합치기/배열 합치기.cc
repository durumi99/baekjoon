#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, M;

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;
	vector <int> a(N);
	vector <int> b(M);
	for(int i = 0 ; i < N ; i++) {
		cin >> a[i];
	}
	for(int i = 0 ; i < M ; i++) {
		cin >> b[i];
	}
	
	int aIdx = 0, bIdx = 0;
	while(aIdx < N || bIdx < M) {
		if(bIdx == M) {
			cout << a[aIdx++] << ' ';
		} else if(aIdx == N) {
			cout << b[bIdx++] << ' ';
		} else if(a[aIdx] <= b[bIdx]) {
			cout << a[aIdx++] << ' ';
		} else {
			cout << b[bIdx++] << ' ';
		}
	}
    return 0;
}