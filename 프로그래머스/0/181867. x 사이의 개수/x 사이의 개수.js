function solution(myString) {
    var answer = myString.split('x').map(el => el.length);
    return answer;
}