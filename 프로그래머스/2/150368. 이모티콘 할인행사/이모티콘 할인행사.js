const disCountRates = [10, 20, 30, 40]
let userLen
let emoticonLen
let users;
let emoticons;
let EPSCnt = 0;
let emoticonSales = 0;
let arr = []

function dfs() {
    // console.log(emoticonLen)
    // console.log(arr.length == emoticonLen)
    if(arr.length == emoticonLen) {
        let wholeSum = 0;
        let eps = 0;
        for(let user of users) {
            let sum = 0
            for(let i = 0 ; i < emoticonLen ; i++) {
                if(user[0] <= arr[i]) {
                    // console.log(emoticons[i] * (100 - arr[i]) * 0.01);
                    sum += emoticons[i] * (100 - arr[i]) * 0.01;
                }
            }
            if(sum >= user[1]) {
                
                eps++;
            } else {
                wholeSum += sum;
            }
        }
        
        
        if(eps > EPSCnt) {
            EPSCnt = eps;
            emoticonSales = wholeSum;
        } else if(eps == EPSCnt && wholeSum > emoticonSales) {
            
            EPSCnt = eps;
            emoticonSales = wholeSum;
        }
        return;
    }
    // console.log(1)
    for(let i = 0 ; i < disCountRates.length ; i++) {
        // console.log(value)
        arr.push(disCountRates[i])
        // console.log(arr)
        dfs()
        arr.pop()
    }
}
function solution(_users, _emoticons) {
    users = _users
    emoticons = _emoticons;
    var answer = [];
    userLen = users.length
    emoticonLen = emoticons.length
    // console.log(emoticonLen)
    dfs()
    answer.push(EPSCnt)
    answer.push(emoticonSales)
    return answer;
}