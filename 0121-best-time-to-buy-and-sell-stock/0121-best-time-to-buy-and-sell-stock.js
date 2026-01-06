/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    let buyPrice = Infinity;
    let sellPrice = 0;
    let curProfit = 0;
    prices.forEach((el) => {
        console.log(el, buyPrice, sellPrice);
        if(buyPrice > el) {
            curProfit = Math.max(curProfit, sellPrice - buyPrice);
            buyPrice = el;
            sellPrice = el;
        }

        if(sellPrice < el) {
            sellPrice = el;
        }
    });
    
    curProfit = Math.max(curProfit, sellPrice - buyPrice);
    return curProfit;
};