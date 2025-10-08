function solution(my_string) {
    var answer = my_string.match(/\d/g).reduce((acc, el) => {
        return acc + ~~el;
    }, 0);
    return answer;
}