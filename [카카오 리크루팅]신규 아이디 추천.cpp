#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string new_id) {
    string answer = "";
    
    //1단계
    for(int i = 0 ; i < new_id.length() ; i++){
        if(new_id[i] >= 'A' && new_id[i] <= 'Z')
            new_id[i] -= 'A' - 'a';
    }
    
    //2단계
    for(int i = 0 ; i < new_id.length() ; i++){
        if(new_id[i] >= 'a' && new_id[i] <= 'z'){
            continue;
        }  
        else if(new_id[i] >= '0' && new_id[i] <= '9'){
            continue;
        }
        else if(new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.'){         
            continue;
        }
        else{
            new_id.erase(i,1);
            i--;
        }
    }
    
    //3단계
    for(int i = 0 ; i < new_id.length() ; i++){
        if(new_id[i] == '.'){
            int tmp = 0;
            while(new_id[i+tmp] == '.'){
                tmp++;
            }
            new_id.replace(i,tmp,".");
        }
    }
    
    //4단계
    if(new_id[0] == '.')
        new_id.erase(0,1);
    if(new_id[new_id.length()-1] == '.')
        new_id.erase(new_id.length()-1,1);
    
    //5단계
    if(new_id == "")
        new_id = "a";
    
    //6단계
    if(new_id.length() >= 16)
        new_id.erase(new_id.begin()+15,new_id.end());
    if(new_id[new_id.length()-1] == '.')
        new_id.erase(new_id.length()-1,1);
    
    //7단계
    while(new_id.length() <= 2){
        new_id += new_id[new_id.length()-1];
    }
    
    answer = new_id;
    return answer;
}