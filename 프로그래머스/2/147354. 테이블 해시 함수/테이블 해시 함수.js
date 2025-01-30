
function solution(data, col, row_begin, row_end) {
    var answer = 0;
    
    function cmp(a, b) {
        if(a[col - 1] === b[col - 1])
            return b[0] - a[0];
        
        return a[col - 1] - b[col - 1];
    }
    
    data.sort(cmp);
    
    for(let i = row_begin - 1;  i < row_end; i++) {
        answer ^= data[i].reduce((acc, el, idx) => {
            return acc + data[i][idx] % (i + 1);
        }, 0); 
    }
    
    return answer;
}