#include <string>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int len = dartResult.length();
    int points[3];
    int tmp = -1;
    
    for(int i = 0 ; i < len ; i++){
        char cur = dartResult[i];
        if(cur >= '0' && cur <= '9'){
            tmp++;
            if(dartResult[i+1] == '0'){
                points[tmp] = 10;
                i++;
            }
            else
                points[tmp] = cur - '0';
        }
        else if(cur == 'S'){
            continue;
        }
        else if(cur == 'D'){
            points[tmp] = points[tmp] * points[tmp];
        }
        else if(cur == 'T'){
            points[tmp] = points[tmp] * points[tmp] * points[tmp];
        }
        else if(cur == '*'){
            if(tmp != 0)
                points[tmp-1] *= 2;
            points[tmp] *= 2;
        }
        else if(cur == '#'){
            points[tmp] *= -1;
        }       
    }

    answer = points[0] + points[1] + points[2];
    return answer;
}