function solution(my_string, index_list) {
    var answer = index_list.map((el) => {
        return my_string[el];
    }).join('');
    
    return answer;
}