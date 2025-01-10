function solution(people, limit) {
    var answer = 0;
    people.sort();
    let cnt = 0;
    let left = 0;
    let right = people.length - 1;
    
    while(left < right) {
        if(people[left] + people[right] > limit) {
            right--;
        } else {
            cnt++;
            left++;
            right--;
        }
    }
    
    answer += cnt;
    answer += people.length - 2 * cnt;
    return answer;
}