function solution(n,a,b)
{
    var answer = 1;
    let minN = Math.min(a, b);
    let maxN = Math.max(a, b);
    
    while(!((maxN - minN === 1) && (minN % 2) === 1)) {
        minN = (minN + 1) >> 1;
        maxN = (maxN + 1) >> 1;
        answer++;
    }
    return answer;
}