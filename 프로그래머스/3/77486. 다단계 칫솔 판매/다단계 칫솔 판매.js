function solution(enroll, referral, seller, amount) {
    var answer = new Array(enroll.length).fill(0);
    const nameMap = new Map();
    
    enroll.forEach((name, idx) => {
        nameMap.set(name, idx);
    });
    
    const adjustment = (name, money) => {
        const curIdx = nameMap.get(name);
        const curMoney = Math.ceil(money * 0.9);
        const nextMoney = money - curMoney;
        const nextName = referral[curIdx];
        
        answer[curIdx] += curMoney;
        
        if (nextName !== '-' && nextMoney >= 1) {
            adjustment(nextName, nextMoney);
        }
    }
    
    seller.forEach((el, idx) => {
        adjustment(el, amount[idx] * 100);
    })
    
    return answer;
}