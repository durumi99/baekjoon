function solution(myString, pat) {
    const answer = [...myString].map((el) => {
        if(el === 'A') {
            return 'B';
        }
        
        return 'A';
    }).join('').includes(pat) ? 1 : 0;
    return answer;
}