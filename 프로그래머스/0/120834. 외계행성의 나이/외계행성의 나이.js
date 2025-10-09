function solution(age) {
    var answer = [...age.toString()].map(el => String.fromCharCode(~~el + 'a'.charCodeAt(0))).join('');
    return answer;
}