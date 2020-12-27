#include <iostream>
using namespace std;
 
char arr[60][60];
bool col[60];
bool row[60];
 
int main()
{
    int n, m;
	cin >> n >> m;
 
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 'X')
            {
                col[i] = true;
                row[j] = true;
            }
        }
        getchar();
    }
 
    int tn = n;
    for (int i = 0; i < n; i++)
        if (col[i])
            tn--;
 
    int tm = m;
    for (int j = 0; j < m; j++)
        if (row[j])
            tm--;
 
    cout << max(tn, tm);
    return 0;
}

