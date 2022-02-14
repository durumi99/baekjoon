#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#define MAX 101
#define INF 100000
using namespace std;
int n;
vector <pair<double,double> > v;
vector <pair<double,double> >cost[MAX];

double answer;
double dis[MAX];
bool sel[MAX];

double len(pair<double,double> p1, pair<double,double> p2){
    double x = abs(p1.first - p2.first);
    double y = abs(p1.second- p2.second);
    return sqrt(x*x + y*y);
}
void input(){
    double tmpx,tmpy;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> tmpx >> tmpy;
        v.push_back({tmpx,tmpy});
    }
}
void solve(){
    dis[0] = 0;
    sel[0] = true;
    
    for(int i = 1 ; i < n ; i++){
        dis[i] = len(v[0],v[i]);
    }
    
    for(int i = 0 ; i <= n - 2; i++){
        double minCost = INF;
        int minIdx = -1;
        for(int j = 0 ; j <= n - 1 ; j++){
            if(sel[j])
                continue;
            if(minCost > dis[j]){
                minCost = dis[j];
                minIdx = j;
            }
        }
        sel[minIdx] = true;
        answer += minCost;
        for(int j = 0 ; j < n ; j++){
            double distance = len(v[minIdx],v[j]);
            if(sel[j])
                continue;
            if(dis[j] > distance)
                dis[j] = distance;
        }
    }
    printf("%.2lf\n",answer);
}
int main() {
    input();
    solve();
    return 0;
}