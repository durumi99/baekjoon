function solution(myString) {
    var answer = myString.split('x').filter(el => el).sort();
    return answer;
}