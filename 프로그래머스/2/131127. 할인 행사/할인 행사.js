function canBuy(index, want, number, discount) {
    let tmp = [...number];
    
    for(let i = index ; i < index + 10 ; i++) {
        const idx = want.findIndex((el) => el == discount[i]);
        
        if(idx != -1)  {
            tmp[idx]--;
        }
    }
    
    for(let i = 0 ; i < tmp.length ; i++) {
        if(tmp[i] > 0)
            return false;
    }
    
    return true;
}

function solution(want, number, discount) {
    var answer = 0;
    for(let i = 0 ; i < discount.length; i++) {
        if(canBuy(i, want, number, discount)) {
            answer++;
        }
    }
    return answer;
}