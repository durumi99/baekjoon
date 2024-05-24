function solution(n,a,b)
{
    var answer = 0;
    
    while(a !== b) {
        a = (a + 1) >> 1;
        b = (b + 1) >> 1;
        
        answer++;
    }
    return answer;
}
