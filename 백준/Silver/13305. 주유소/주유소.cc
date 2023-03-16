#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int atm[1111];
int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    int n; cin >> n;
    vector <long long> fuel,dist;
    for(int i = 0 ; i < n-1 ; i++){
        long long tmp; cin >> tmp;
        dist.push_back(tmp);
    }
    for(int i = 0 ; i < n ; i++){
        long long tmp; cin >> tmp;
        fuel.push_back(tmp);
    }
    long long curFuel = fuel[0];
    long long res = 0;
    for(int i = 0 ; i < n-1 ; i++){
        if(fuel[i] < curFuel)
            curFuel = fuel[i];
        res += dist[i] * curFuel;
    }
    cout << res;
    return 0;
}