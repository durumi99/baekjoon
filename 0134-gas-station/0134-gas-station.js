/**
 * @param {number[]} gas
 * @param {number[]} cost
 * @return {number}
 */
var canCompleteCircuit = function(gas, cost) {
    const n = gas.length;
    const canComplete = (start) => {
        let curTank = 0;

        for(let i = 0 ; i < n ; i++) {
            const idx = (i + start) % n;
            curTank += gas[idx];

            if (curTank < cost[idx]) {
                return false;
            } else {
                curTank -= cost[idx];
            }
        };

        return true;
    };

    for(let i = 0 ; i < n ; i++) {
        if(gas[i] === 0) {
            continue;
        }
        
        if(canComplete(i)) {
            return i;
        }
    }

    return -1;
};