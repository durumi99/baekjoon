function solution(my_string) {
    var answer = my_string.replace(/[A-Za-z]/g,' ').split(' ').reduce((acc, el) => {
        return acc + ~~el;
    }, 0);
    return answer;
}