function solution(str_list) {
    var answer = [];
    str_list.some((el, idx) => {
        if(el === 'l') {
            answer = str_list.slice(0, idx);
            return true;
        } else if(el === 'r') {
            answer = str_list.slice(idx + 1);
            return true;
        }
    });
    
    return answer;
}