let users;
let emoticons;
let discountRates = [];
let answer = [0, 0];
 
function solution(_users, _emoticons) {
    users = _users;
    emoticons = _emoticons;
    dfs(0);
    return answer;
}

function dfs(idx) {
    if(idx === emoticons.length) {
        const [registerAmount, revenue] = getResult();
        
        if(registerAmount > answer[0]) {
            answer = [registerAmount, revenue];
        } else if(registerAmount === answer[0] && revenue > answer[1]) {
            answer = [registerAmount, revenue];
        }
        return;
    }
    
    for(let i = 10 ; i <= 40 ; i += 10) {
        discountRates.push(i);
        dfs(idx + 1);
        discountRates.pop();
    }
}

function getResult() {
    let curRegisterAmount = 0;
    let curRevenue = 0;
    
    users.forEach((user) => {
        const percentage = user[0];
        const limitPrice = user[1];
        
        const sum = emoticons.reduce((acc, price, idx) => {
            const curDiscountRates = discountRates[idx];
            
            if(curDiscountRates >= percentage) {
                acc += price * (100 - curDiscountRates) / 100;
            }
            
            return acc;
        }, 0);
        
        if (sum >= limitPrice) {
            curRegisterAmount++;
        } else {
            curRevenue += sum;
        }
    });
    
    return [curRegisterAmount, curRevenue];
}