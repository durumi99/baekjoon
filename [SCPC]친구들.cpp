/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>

using namespace std;

int Answer;
int group[100001];

int find(int x) {
    if (group[x] == x) {
        return x;
    } else {
        return group[x] = find(group[x]);
    }
}
void merge(int x,int y){
    x = find(x);
    y = find(y);
    if(x == y)
        return;
    group[y] = x;
}
int main(int argc, char** argv)
{
	int T, test_case;
	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using cin function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */	

	// freopen("input.txt", "r", stdin);

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{

		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		int N; cin >> N;
		int D[100001];
        for(int i = 1 ; i <= N ; i++){
        	group[i] = i;
        }
		for(int i = 1 ; i <= N ; i++){
		    cin >> D[i];
		    if(i+D[i] <= N){
		        merge(i,i+D[i]);
		    }
		}
		int visited[100001]= {0,};
		for(int i = 1 ; i <= N ; i++){
		    group[i] = find(group[i]);
		    if(visited[group[i]] == 0)
		        Answer++;
		    visited[group[i]] = 1;
		}
		/////////////////////////////////////////////////////////////////////////////////////////////
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}