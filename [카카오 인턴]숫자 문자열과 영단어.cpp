#include string
#include vector
#include iostream

using namespace std;

string str[10] = {zero,one,two,three,four,five,six,seven,eight,nine};

int solution(string s) {
    int answer = 0;
    stringsize_type n;
    for(int i = 0 ; i  10 ; i++){
        while(true){
            n = s.find(str[i]);
            if( n == stringnpos )
                break;
            s.replace(n,str[i].length(),to_string(i));
        }
    }
    answer = stoi(s);
    return answer;
}