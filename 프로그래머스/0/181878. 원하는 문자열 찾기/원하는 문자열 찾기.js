function solution(myString, pat) {
    var answer = +myString.toLowerCase().includes(pat.toLowerCase());
    return answer;
}