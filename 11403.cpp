#include <iostream>
#include <algorithm>
using namespace std;

#define INF 987654321

int n;
int arr[101][101];
void floyd(){
     for (int i = 1; i <= n; i++)             
        for (int j = 1; j <= n; j++)         
            for (int k = 1; k <= n; k++)     
                if (arr[j][i] != 0 && arr[i][k] != 0)        
                    arr[j][k] = 1;
}
int main() {
    cin >> n;
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= n ; j++)
            cin >> arr[i][j];
    floyd();
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++)
            cout << arr[i][j] << ' ';
        cout <<'\n';
    }
    return 0;
}