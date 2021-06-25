#include <iostream>
using namespace std;

int main() {
	int l,p,v,cs=1,answer=0;
	while(cin >> l >> p >> v){
		if(l == 0 && p == 0 && v == 0)
			break;
		answer += l * (v/p);
		if( (v%p) < l)
			answer += (v%p);
		else
			answer += l;
		cout << "Case " << cs << ": " << answer << '\n';
		cs++;
		answer = 0;
	}

	return 0;
}