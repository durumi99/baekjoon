function solution(num_list) {
    var answer = 0;
    answer = num_list.reduce((acc, el) => {
        while(el !== 1) {
            acc++;
            if (el % 2) {
                el = (el - 1 ) / 2;
            } else {
                el /= 2;
            }
        }
        
        return acc;
    }, 0);
    
    return answer;
}