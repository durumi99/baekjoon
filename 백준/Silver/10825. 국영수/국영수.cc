#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
struct Grade {
	string name;
	int korea, english, math;
};

bool cmp(Grade a, Grade b) {
	if(a.korea == b.korea) {
		if(a.english == b.english) {
			if(a.math == b.math) {
				return a.name < b.name;
			}
			
			return a.math > b.math;
		}
		
		return a.english < b.english;
	}
	
	return a.korea > b.korea;
}
int main() {
	// your code goes here
	cin >> N;
	Grade grade[N];
	for(int i = 0 ; i <  N ; i++){
		string n;
		int k,e,m; 
		cin >> n >> k >> e >> m;
		grade[i] = {n, k, e, m};
	}
	sort(grade, grade+N, cmp);
	
	for(int i = 0 ; i < N ; i++) {
		cout << grade[i].name << '\n';
	}
	return 0;
}