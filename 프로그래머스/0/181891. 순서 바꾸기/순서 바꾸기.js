function solution(num_list, n) {
    var answer = [];
    for(let i = n ; i < num_list.length + n ; i++) {
        answer.push(num_list[i % num_list.length]);
    }
    return answer;
}