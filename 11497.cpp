#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n;
    int tc ; cin >> tc;
    while(tc--){
        cin >> n;
        vector <int> l;
        for(int i = 0 ; i < n ; i++){
            int tmp; cin >> tmp;
            l.push_back(tmp);
        }
        sort(l.begin(), l.end());
        vector <int> v(n);
        for(int i = 0 ; i < n  ; i++){
        	if((i % 2) == 0){
        		v[i/2] = l[i];
        	}
        	else{
        		v[n-i/2-1] = l[i];
        	}
        }
        int answer = 0;
        for(int i = 0 ; i < n ; i++){
        	int dif = abs(v[i] - v[(i+1)%n]);
        	answer = (dif > answer) ? dif : answer;
        }
        cout << answer << '\n';
    }
    return 0;
}