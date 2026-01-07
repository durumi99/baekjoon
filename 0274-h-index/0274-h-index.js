/**
 * @param {number[]} citations
 * @return {number}
 */
var hIndex = function(citations) {
    let answer = Math.max(...citations);

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
        return acc;
    }, 0);
}