/**
 * @param {number[]} ratings
 * @return {number}
 */
var candy = function(ratings) {
    const candies = new Array(ratings.length).fill(1);

    for(let i = 1 ; i < candies.length ; i++) {
        if(ratings[i] > ratings[i - 1]) {
            candies[i] = candies[i - 1] + 1;
        }
    }

    for(let i = candies.length - 1 ; i >= 0 ; i--) {
        if(ratings[i] > ratings[i + 1]) {
            if (candies[i] <= candies[i + 1]){ 
                candies[i] = candies[i + 1] + 1;
            }
            // candies[i] = candies[i + 1] + 1;
        }
    }

    return candies.reduce((acc, el) => {
        return acc + el;
    }, 0);
};