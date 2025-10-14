function solution(cards1, cards2, goal) {
    var answer = '';
    let idx1 = 0, idx2 = 0;
    answer = goal.every((el) => {
        if(el === cards1[idx1]) {
            idx1++;
            return true;
        } else if (el === cards2[idx2]) {
            idx2++;
            return true;
        }
        
        return false;
    }) ? 'Yes' : 'No';
    return answer;
}