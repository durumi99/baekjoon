/**
 * @param {number[]} citations
 * @return {number}
 */
var hIndex = function(citations) {
    citations.sort((a, b) => b - a);
    let answer = citations[0];

    while(answer) {
        if(answer <= getCount(answer, citations)) {
            break;
        }

        answer--;
    }

    return answer;
};

function getCount(n, citations) {
    return citations.reduce((acc, el) => {
        if(el >= n) {
            acc++;
        }
        console.log(acc, el, n)
        return acc;
    }, 0);
}