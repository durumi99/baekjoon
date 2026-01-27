// /**
//  * @param {number[][]} intervals
//  * @return {number[][]}
//  */
// var merge = function(intervals) {
//     intervals.sort((a, b) => {
//         // if(a[0] === b[0]) {
//         //     return a[1] - b[1];
//         // }
//         return a[0] - b[0];
//     });

//     const answer = [];
//     let [left, right] = intervals[0];
//     for(let i = 1 ; i < intervals.length ; i++) {
//         if(intervals[i][0] <= right) {
//             right = Math.max(right, intervals[i][1]);
//         } else {
//             answer.push([left, right]);
//             [left, right] = intervals[i];
//         }
//     }
//     answer.push([left, right]); 
//     return answer;
// };

/**
 * @param {number[][]} intervals
 * @return {number[][]}
 */
var merge = function(intervals) {
    // sort incremental order of start_i

    intervals.sort((a,b) => (a[0] - b[0]))

    const result = []

    let prev = intervals[0]

    for (let i = 1; i < intervals.length; i++) {
        const curr = intervals[i]
        if (prev[1] >= curr[0]) {
            prev[1] = Math.max(curr[1], prev[1])
        } else {
            result.push(prev)
            prev = curr
        }
    }
    result.push(prev)
    return result
};