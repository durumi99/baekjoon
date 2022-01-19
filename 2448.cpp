#include <iostream>

using namespace std;
char arr[4444][6666];
void print(int row,int col){
    arr[row][col] = '*';
    
    // 두번째 줄 (* 2개)
    arr[row + 1][col - 1] = '*';
    arr[row + 1][col + 1] = '*';
    
    // 세번째 줄 (* 5개)
    for(int i = 0; i < 5; i++)
        arr[row + 2][col - 2 + i] = '*';
}
void star(int len, int row, int col)
{
   if(len == 3){
       print(row,col);
       return;
   }
   star(len / 2, row, col);
   star(len / 2, row + len / 2, col - len / 2);
   star(len / 2, row + len / 2, col + len / 2);
}
int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2 * n - 1; j++)
        {
            arr[i][j] = ' ';
        }
    }
    star(n,0,n-1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2 * n - 1; j++)
        {
            cout << arr[i][j];
        }
        cout << '\n';
    }
    return 0;
}