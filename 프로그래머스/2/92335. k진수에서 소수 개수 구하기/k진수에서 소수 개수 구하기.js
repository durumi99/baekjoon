function solution(n, k) {
    const str = n.toString(k)
    const regex = /[1-9]*/g;
    const arr = str.match(regex).filter(e => e !== '' && e !== '1');
        
    let answer = 0;
    
    arr.forEach(e => {        
        for(let i = 2 ; i<= Math.sqrt(e);i++) {
            if(e % i === 0) 
                return;
        }
        
        answer++;
    })
    
    return answer;
}
