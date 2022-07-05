/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>

using namespace std;

int Answer;

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
		int a = 0, b = 0;
		string n; cin >> n;
		for(int i = 0 ; i < n.length() ; i++){
		    if(n[i] == 'A'){
		        a++;
		    }
		    else if(n[i] == 'B'){
		        b++;
		    }
		    if(a == 21){
		        Answer = 1;
		        break;
		    }
		    else if(b == 21){
		        Answer = 2;
		        break;
		    }
		}
		/////////////////////////////////////////////////////////////////////////////////////////////
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		if(Answer == 1)
		    cout << "Alice" << endl;
		else if(Answer == 2)
		    cout << "Bob" << endl;
		else
		    cout << "Playing" << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}