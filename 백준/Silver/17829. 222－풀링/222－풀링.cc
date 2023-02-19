#include <bits/stdc++.h>

#define MAX 1024

using namespace std;

int N;
int arr[MAX][MAX];

int dq(int y, int x , int size) {
	if(size == 1) {
		return arr[y][x];
	}
    
	vector <int> v;
	for(int i = 0 ; i < size ; i+= size/2) {
		for(int j = 0 ; j < size ; j+= size/2) {
			v.push_back(dq(y+i, x+j, size/2));
		}
	}
	sort(v.begin(), v.end());
	return v[2];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    
    for(int i = 0 ; i < N ; i++) {
    	for(int j = 0 ; j < N ; j++) {
	    	cin >> arr[i][j];
    	}
    }
    
    cout << dq(0, 0, N);
    return 0;
}