function solution(sequence, k) {
    var answer = [];
    let curSum = sequence[0];
    let left = 0;
    let right = 0;
    while(left <= right && right < sequence.length) {
        if(curSum == k) {
            if(answer.length == 0) {
                answer.push(left, right);
            } else {
                if(right - left < answer[1] - answer[0]) {
                    answer = [left, right];
                }
            }
            right++;
            curSum += sequence[right];
        } else if (curSum < k) {
            right++;
            curSum += sequence[right];
        } else {
            curSum -= sequence[left];
            left++;
        }
        // console.log(left, right);
    }
    return answer;
}