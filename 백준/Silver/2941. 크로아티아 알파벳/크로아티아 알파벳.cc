#include <iostream>
#include <vector>

using namespace std;
vector <string> v = {"c=","c-","dz=","d-","lj","nj","s=","z="};

int main() {
    string s; cin >> s;
    for(int i = 0 ; i < v.size() ; i++){
        while(1){
            int idx = s.find(v[i]);
            if (idx == string::npos)
                break;
            s.replace(idx,v[i].length(),"#");
        }
    }
    cout << s.length() << '\n';
    return 0;
}