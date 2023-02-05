#include <iostream>
#include <set>

#define MAX 1001
using namespace std;
int N;
int x1[MAX], x2[MAX], y1[MAX], y2[MAX];

int root[MAX];

bool check(int i, int j) {
	if(x1[j] > x2[i] || y1[j] > y2[i] || x1[i] > x2[j] || y1[i] > y2[j])
		return false;
	if(x1[j] > x1[i] && x2[i] > x2[j] && y1[j] > y1[i] && y2[i] > y2[j])
		return false;
	if(x1[i] > x1[j] && x2[j] > x2[i] && y1[i] > y1[j] && y2[j] > y2[i])
		return false;

	return true;	
};

int find(int x) {
	if(root[x] == x) {
		return x;
	} else {
		return root[x] = find(root[x]);
	}
};

void unionT(int x, int y) {
	x = find(x);
	y = find(y);
	if(x == y)
		return;
		
	if(x < y)
		root[y] = x;
	else
		root[x] = y;
}
int main() {
	// your code goes here
	cin >> N;
	for(int i = 1 ; i <= N ; i++) {
		cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
		root[i] = i;
	}
	for(int i = 0 ; i <= N-1 ; i++) {
		for(int j = i+1 ; j <= N ; j++) {
			if(check(i, j)) {
				unionT(i, j);
			}
		}
	}
	
	set <int> s;
	for(int i = 0 ; i <= N ; i++) {
		// cout << root[i] << ' ';
		s.insert(find(root[i]));
	}
	// cout << '\n';
	cout << s.size()-1;
	return 0;
}