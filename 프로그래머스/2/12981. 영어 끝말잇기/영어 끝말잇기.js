function solution(n, words) {
    var answer = [0 , 0];
    let s = new Set();
    s.add(words[0]);
    
    for (let i = 1 ; i < words.length ; i++) {
        if(s.has(words[i])) {
            return  [~~(i % n) + 1, ~~(i / n) + 1];
        }
        
        const firstChar = words[i][0];
        const prevLen = words[i - 1].length;
        const lastChar = words[i - 1][prevLen - 1];
        
        if(firstChar != lastChar) {
            return  [~~(i % n) + 1, ~~(i / n) + 1];
        }
        
        s.add(words[i]);
    }
    
    return answer;
}