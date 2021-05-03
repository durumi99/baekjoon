#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";    
    int left = 10,right = 12,disL,disR;
    for(int i = 0 ; i < numbers.size() ; i++){
        if(numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7){
            left = numbers[i];
            answer.append("L");
        }
        else if(numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9){
            right = numbers[i];
            answer.append("R");
        }
        else{      
            if(numbers[i] == 0)
                numbers[i] = 11;
            disL = abs((left-1)/3 - (numbers[i]-1)/3)+abs((left-1)%3 - (numbers[i]-1)%3);
            disR = abs((right-1)/3 - (numbers[i]-1)/3)+abs((right-1)%3 - (numbers[i]-1)%3);
            if(disL < disR || (disL == disR && hand == "left") ){
                left = numbers[i];
                answer.append("L");
            }
            else{
                right = numbers[i];
                answer.append("R");
            }
        }
    }
    return answer;
}