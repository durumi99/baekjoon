function solution(my_string) {
    var answer = my_string.match(/\d/g).map(el => ~~el).sort();
    return answer;
}