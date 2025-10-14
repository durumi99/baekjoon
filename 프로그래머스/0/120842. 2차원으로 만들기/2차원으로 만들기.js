function solution(num_list, n) {
    var answer = num_list.map((_, idx) => {
       if(idx % n === 0) {
           return num_list.slice(idx, idx + n);
       } 
    }).filter(el => el);
    return answer;
}