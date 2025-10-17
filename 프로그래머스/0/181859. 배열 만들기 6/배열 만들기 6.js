function solution(arr) {
    var answer = [];
    let i = 0;
    while(i < arr.length) {
        if(answer.length === 0) {
            answer.push(arr[i++]);
        } else if (answer.at(-1) === arr[i]) {
            answer.pop();
            i++;
        } else {
            answer.push(arr[i++]);
        }
    }
    if(answer.length === 0) {
        return [-1];
    }
    return answer;
}