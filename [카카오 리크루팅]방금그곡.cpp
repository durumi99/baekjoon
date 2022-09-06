#include <string>
#include <vector>
#include <cstring>

using namespace std;

string pitches[12]= {"C#","C","D#","D","E","F#","F","G#","G","A#","A","B"};
// a b c d e  f g h i j  k l 
void convertPitches(string &str){
    for(int i = 0 ; i < 12 ; i++){
        while(true){
            auto n = str.find(pitches[i]);
            if(n != std::string::npos){
                string tmp(1,'a'+i);
                str.replace(n,pitches[i].length(),tmp);
            }
            else
                break;
        }
    }
}
string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    int curMelodyLen = 0;
    convertPitches(m);
    for(int i = 0 ; i < musicinfos.size() ; i++){
        char str[3000];
        strcpy(str,musicinfos[i].c_str());
        
        char *ptr = strtok(str,",");
        int start = (ptr[0]-'0') * 600 + (ptr[1]-'0') * 60 + (ptr[3]-'0') * 10 + (ptr[4]-'0');
        ptr = strtok(NULL,",");
        int end = (ptr[0]-'0') * 600 + (ptr[1]-'0') * 60 + (ptr[3]-'0') * 10 + (ptr[4]-'0');
        int playtime = end - start;
        
        ptr = strtok(NULL,",");
        string title(ptr);    
        ptr = strtok(NULL,",");
        string melody(ptr);
        convertPitches(melody);
        
        string wholeMelody="";
        for(int j = 0 ; j < playtime ; j++){
            wholeMelody += melody[j % melody.length()];
        }
           
        if(m.length() > wholeMelody.length())
            continue;
        auto n = wholeMelody.find(m);  
        if(n != std::string::npos && wholeMelody.length() > curMelodyLen){
            answer = title;
            curMelodyLen = wholeMelody.length();
        }
    }
    return answer;
}