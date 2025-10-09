function solution(str_list, ex) {
    var answer = '';
    answer = str_list.reduce((acc, el) => {
        if(!el.includes(ex)) {
            acc += el;
        }    
        return acc;
    }, '');
    
    return answer;
}