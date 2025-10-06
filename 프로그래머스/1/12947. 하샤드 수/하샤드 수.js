function solution(x) {
    const target = String(x).split('').reduce((acc, el) => {
        return acc + Number(el);
    }, 0);
    
    return x % target === 0;
}