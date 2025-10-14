function solution(myString, pat) {
    var answer = myString.substr(0, myString.lastIndexOf(pat) + pat.length);
    return answer;
}