#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector< vector<int> > candidateKeys;

bool checkUnique(vector <int> key, vector<vector<string>> relation){
    set <string > s;
    for(int i = 0 ; i < relation.size() ; i++){
        string tmp ="";
        for(int j = 0 ; j < key.size() ; j++){
            tmp += relation[i][key[j]];
        }
        s.insert(tmp);
    }
    if(s.size() == relation.size())
        return true;
    else
        return false;
}

bool checkMinimal(vector <int> key, vector<vector<string>> relation){
    if(candidateKeys.size() == 0)
        return true;
    for(int t = 1 ; t <= key.size() ; t++){
        vector <int> s;
        vector <int> temp;
        for(int i = 0 ; i < key.size() ; i++){
            s.push_back(key[i]);
            if(i < t)
                temp.push_back(1);
            else
                temp.push_back(0);
        }

        do{
            vector <int> tmp;
            for (int i = 0; i < s.size(); ++i) {
                if (temp[i] == 1){
                    tmp.push_back(s[i]);
                    }
            }
            auto it = find(candidateKeys.begin(), candidateKeys.end(), tmp);
            if (it != candidateKeys.end()) 
                return false;
            tmp.clear();
        } while (prev_permutation(temp.begin(), temp.end()));
    }
    return true;   
}

void makeKey(int keySize,vector<vector<string>> relation){
    vector < vector<int> > keys;
    vector <int> s;
    vector <int> temp;
    for(int i = 0 ; i < relation[0].size() ; i++){
        s.push_back(i);
        if(i < keySize)
            temp.push_back(1);
        else
            temp.push_back(0);
    }
    
    do{
        vector <int> tmp;
        for (int i = 0; i < s.size(); ++i) {
            if (temp[i] == 1){
                tmp.push_back(s[i]);
            }
        }
        keys.push_back(tmp);
        tmp.clear();
    } while (prev_permutation(temp.begin(), temp.end()));

    for(int i = 0 ; i < keys.size() ; i++){
        if(checkMinimal(keys[i],relation) && checkUnique(keys[i],relation)){
            candidateKeys.push_back(keys[i]);
        }
    }
    
}
int solution(vector<vector<string>> relation) {
    int answer = 0;
    int rowLen = relation.size();
    int colLen = relation[0].size();
    for(int i = 1 ; i <= colLen ; i++)
        makeKey(i,relation);
    
    answer = candidateKeys.size();
    return answer;
}