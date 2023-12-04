function solution(n) {
    var answer = 0;
    let left = 1
    let sum = 1
    let right = 1
    while(left <= right && right <= n) {
        if(sum == n) {
            answer++    
            sum += ++right
            // console.log(left, right)
        } else if(sum < n) {
            sum += ++right
        } else {
            sum -= left++
        }
        
    }
    return answer;
}
