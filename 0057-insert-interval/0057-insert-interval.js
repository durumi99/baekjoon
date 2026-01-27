/**
 * @param {number[][]} intervals
 * @param {number[]} newInterval
 * @return {number[][]}
 */
var insert = function(intervals, newInterval) {
    const concatIntervals = [...intervals, newInterval].sort((a, b) => {
        return a[0] - b[0];
    });

    const answer = [];
    let prev = concatIntervals[0];
    for(let i = 1 ; i < concatIntervals.length ; i++) {
        if(concatIntervals[i][0] <= prev[1]) {
            prev[1] = Math.max(prev[1], concatIntervals[i][1]);
        } else {
            answer.push(prev);
            prev = concatIntervals[i];
        }
    }
    answer.push(prev); 
    return answer;
};