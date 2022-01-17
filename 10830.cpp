#include <iostream>
#define ll long long
#define MOD 1000
using namespace std;
int n;
ll b;
ll matrix[5][5], mul[5][5],tmp[5][5];
void matmul(ll a[5][5], ll b[5][5], ll res[5][5])    // a, b 는 곱할 행렬, res 는 결과값 담아줄 행렬
{
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            tmp[i][j] = 0;
            for(int k = 0 ; k < n ; k++){
                tmp[i][j] += a[i][k]*b[k][j];
            }
            tmp[i][j] %= MOD;
        }
    }
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            res[i][j] = tmp[i][j];
        }
    }
}
void output(){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cout << matrix[i][j] << ' ';
        }
        cout << '\n';
    }
}
void f(ll b){
    while(b > 0){
        if(b % 2 == 1)
            matmul(matrix,mul,matrix);
        matmul(mul,mul,mul);
        b /=2;
    }
    output();
}
int main() {
    cin >> n >> b;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> mul[i][j];
        }
       matrix[i][i] = 1;
    }
    f(b);
    return 0;
}