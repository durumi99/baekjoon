function solution(n)
{
    const answer = [...String(n)].reduce((acc, el) => {
        return acc + Number(el);
    }, 0);

    return answer;
}