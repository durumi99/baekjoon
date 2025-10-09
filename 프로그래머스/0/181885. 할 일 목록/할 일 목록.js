function solution(todo_list, finished) {
    var answer = todo_list.filter((el, idx) => !finished[idx]);
    return answer;
}