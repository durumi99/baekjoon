#include <iostream>
using namespace std;
int n;
int graph[100][100];
void floyd(){
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < n ; j++)
			for(int k = 0 ; k < n ; k++)
				if(graph[j][k] == 0 && graph[j][i] == 1 && graph[i][k] == 1)
					graph[j][k] = 1;
}
int main() {
	cin >> n;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++)
			cin >> graph[i][j];
	}

	floyd();
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++)
			cout << graph[i][j] << ' ';
		cout << '\n';
	}
	return 0;
}