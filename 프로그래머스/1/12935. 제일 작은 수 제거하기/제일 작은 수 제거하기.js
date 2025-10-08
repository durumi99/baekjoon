function solution(arr) {
    if(arr.length === 1) {
        return [-1];
    }
    
    let min = Infinity;
    arr.forEach((el) => {
        min = Math.min(el, min);
    });
    
    return arr.filter(el => el !== min);
}