function solution(arr) {
    const lengths = Array.from({length : 11}, (_,idx ) => Math.pow(2, idx));
    let answer;
    lengths.some((len) => {
        if(len >= arr.length) {
            answer = arr.concat(Array(len - arr.length).fill(0));
            return true;
        }
    })
    
    return answer;
}
