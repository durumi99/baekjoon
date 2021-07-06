#include <iostream>
#include <map>
using namespace std;

int main() {
    int maxN = 0;
    char maxL;
    bool check;
    map <char,int> alphabet;
    for(char i = 'A' ; i <= 'Z' ; i++)
        alphabet.insert({i,0});
    string word;
    cin >> word;
    for(int i = 0 ; i < word.size() ; i++){
        if(word[i] >= 'a' )
            word[i] -= 32;
       ++alphabet[word[i]];
    }
    for (std::map<char,int>::iterator it=alphabet.begin(); it!=alphabet.end(); ++it){
        if(it->second > maxN){
            maxN = it->second;
            maxL = it->first;
            check = false;
        }
        else if (it->second == maxN){
            check = true;
        }
    }
    if(check)  
        cout << '?';
    else
        cout << maxL;
    return 0;
}