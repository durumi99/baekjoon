#include <iostream>
#include <queue>

using namespace std;

struct cmp{
    bool operator()(int a,int b){
    if(abs(a) == abs(b)){
        return a > b;
    }
    else
        return abs(a) > abs(b);
    }
};
int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    priority_queue <int,vector<int>,cmp> pq;
    int n; cin >> n;
    for(int i = 0 ; i < n ; i++){
        int tmp; cin >> tmp;
        if(tmp == 0){
            if(!pq.empty()){
                cout << pq.top() << '\n';
                pq.pop();
            }
            else
                cout << 0 << '\n';
        }
        else
            pq.push(tmp);
    }
    return 0;
}
