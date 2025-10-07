function solution(num_list) {
    const tmp = num_list.reduce((acc, el) => {
        if(el % 2) {
            acc++;
        }
        
        return acc;
    }, 0);
    var answer = [num_list.length - tmp, tmp];
    return answer;
}