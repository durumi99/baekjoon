function solution(my_string) {
    var answer = my_string.split(' ').filter(el => el !== '');
    return answer;
}