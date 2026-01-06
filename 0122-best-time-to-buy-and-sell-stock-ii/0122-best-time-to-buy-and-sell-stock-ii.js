/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    let buyPrice = prices[0];
    let sellPrice = prices[0];
    let sumProfit = 0;
    for(let i = 1 ; i < prices.length ; i++) {
        if(prices[i] < sellPrice) {
            sumProfit += sellPrice - buyPrice;
            buyPrice = prices[i];
            sellPrice = prices[i];
        }

        if(prices[i] > sellPrice) {
            sellPrice = prices[i];
        }
    }

    sumProfit += sellPrice - buyPrice;
    return sumProfit;
};