/**
 * @param {number[][]} points
 * @return {number}
 */
var findMinArrowShots = function(points) {
    points.sort((a, b) => {
        return a[0] - b[0];
    });

    const answer = [];
    let prev = points[0];
    for(let i = 1 ; i < points.length ; i++) {
        if(points[i][0] <= prev[1]) {
            prev[1] = Math.min(prev[1], points[i][1]);
        } else {
            answer.push(prev);
            prev = points[i];
        }
    }

    answer.push(prev); 
    return answer.length;
};