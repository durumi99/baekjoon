#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#define INF 1e9
using namespace std;

int main() {
    int TC; cin >> TC;
    while(TC--){
        int n,sum_x,sum_y;
        long long ans = -1,now;
        vector < pair <int,int> > point;
        vector <int> comb;

        cin >> n;
        point.resize(n);
        comb.resize(n,0);
        for(int i = 0 ; i < n ; i++){
            cin >> point[i].first >> point[i].second;
            if( i >= n /2)
                comb[i] = 1;
        }
        
        do{
            sum_x = sum_y = 0;
            for(int i = 0 ; i < n ;i++){
                if(comb[i]){
                    sum_x += point[i].first;
                    sum_y += point[i].second;
                }
                else{
                    
                    sum_x -= point[i].first;
                    sum_y -= point[i].second;
                }
            }
            now = pow(sum_x,2) + pow(sum_y,2);
            if(ans == -1 || ans > now)
                ans = now;
        }while(next_permutation(comb.begin(),comb.end()));
        
        cout << fixed;
        cout.precision(12);
        cout << sqrt(ans) << '\n';
    }
    return 0;
}