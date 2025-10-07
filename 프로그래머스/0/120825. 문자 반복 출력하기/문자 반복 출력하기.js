function solution(my_string, n) {
    var answer = my_string.split('').map(el => {
        let tmp = '';
        for(let i = 0 ; i < n ; i++) {
            tmp += el;
        }
        return tmp;
    }).join('');
    return answer;
}