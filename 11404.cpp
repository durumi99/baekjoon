
#include <iostream>
#include <algorithm>
using namespace std;

#define INF 987654321
#define ARRSIZE 101
int n,m;
int arr[ARRSIZE][ARRSIZE];
int tmp1,tmp2,tmp3;

void floyd(){
     for (int i = 1; i <= n; i++)             
        for (int j = 1; j <= n; j++)         
            for (int k = 1; k <= n; k++)     
                if (arr[j][i] != INF && arr[i][k] != INF)        
                    arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
}
int main() {
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1; j <= n ; j++)
            arr[i][j] = INF;
           
    for(int i = 0 ; i < m ; i++){
        cin >> tmp1 >> tmp2 >> tmp3;
        if(arr[tmp1][tmp2] > tmp3)
            arr[tmp1][tmp2] = tmp3;
    }
    
    floyd();
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if ( i == j || arr[i][j] == INF)
                cout << 0 << " ";
            else
                cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}