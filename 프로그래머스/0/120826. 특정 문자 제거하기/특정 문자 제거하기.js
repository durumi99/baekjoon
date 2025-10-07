function solution(my_string, letter) {
    var answer = my_string.split('').filter(el => el !== letter).join('');
    return answer;
}