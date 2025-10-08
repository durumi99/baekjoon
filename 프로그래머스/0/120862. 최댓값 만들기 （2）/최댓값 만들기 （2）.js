function solution(numbers) {
    let maxN = -Infinity;
    
    numbers.forEach((el1, idx1) => {
        numbers.forEach((el2, idx2) => {
            if(idx1 !== idx2) {
                maxN = Math.max(maxN, el1 * el2);
            }
        })
    });
    
    return maxN;
}