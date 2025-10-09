function solution(arr, delete_list) {
    var answer = arr.filter(el => !(new Set(delete_list).has(el)));
    return answer;
}