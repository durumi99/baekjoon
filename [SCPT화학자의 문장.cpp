/* Please use the chemical symbols in the periodic table below when you solve this problem.
   "H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al",
   "Si", "P", "S", "Cl", "Ar", "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe",
   "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr",
   "Y","Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb",
   "Te", "I", "Xe", "Cs", "Ba", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au",
   "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Rf", "Db", "Sg",
   "Bh", "Hs", "Mt", "Ds", "Rg", "Cn", "Fl", "Lv", "La", "Ce", "Pr", "Nd",
   "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Ac",
   "Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", "Md",
   "No", "Lr"   */

/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int Answer;

vector <string> table={
    "H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al",
   "Si", "P", "S", "Cl", "Ar", "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe",
   "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr",
   "Y","Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb",
   "Te", "I", "Xe", "Cs", "Ba", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au",
   "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Rf", "Db", "Sg",
   "Bh", "Hs", "Mt", "Ds", "Rg", "Cn", "Fl", "Lv", "La", "Ce", "Pr", "Nd",
   "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Ac",
   "Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", "Md",
   "No", "Lr"
};

int f(string s,int idx){
    if(idx == s.length())
        return 1;
    string tmp;
    int a = 0;
    tmp += s[idx];
    auto id1 = find(table.begin(), table.end(), tmp);
    if(id1 != table.end())
        return f(s,idx+1);
    tmp += s[idx+1];
    auto id2 = find(table.begin(), table.end(), tmp);
    if(id2 != table.end())
        return f(s,idx+2);
    else
        return 0;
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
    for(int i = 0 ; i < table.size() ; i++){
        for(int j = 0 ; j < table[i].length(); j++){
            if(table[i][j] >= 'A' && table[i][j] <= 'Z')
                table[i][j] -= 'A' - 'a';
        }
    }
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{

		Answer = 1;
		/////////////////////////////////////////////////////////////////////////////////////////////
		string N; cin >> N;
		vector <int> v;
		
// 		queue <int> q;
// 		q.push(0);
// 		while(!q.empty()){
// 		    int cur = q.front();
// 		    q.pop();
// 		    if(cur == N.length()){
// 		        Answer = 1;
// 		        break;
// 		    }
// 		    string tmp;
//             tmp += N[cur];
//             auto id1 = find(table.begin(), table.end(), tmp);
//             if(id1 != table.end())
//                 q.push(cur+1);
//             tmp += N[cur+1];
//             auto id2 = find(table.begin(), table.end(), tmp);
//             if(id2 != table.end())
//                 q.push(cur+2);
// 		}
		Answer = f(N,0);
		/////////////////////////////////////////////////////////////////////////////////////////////
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		if(Answer)
		    cout << "YES" << endl;
		else
    		cout << "NO" << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}