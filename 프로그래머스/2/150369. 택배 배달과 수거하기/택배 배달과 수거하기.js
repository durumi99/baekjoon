function solution(cap, n, deliveries, pickups) {
    var answer = 0;
    
    while(deliveries.length !== 0 || pickups.length !== 0) {
        while(deliveries[deliveries.length - 1] === 0) {
            deliveries.pop();
        }
        
        while(pickups[pickups.length - 1] === 0) {
            pickups.pop();
        }  
        
        const curMove = Math.max(deliveries.length, pickups.length);
        let curCaps = [cap, cap];
        // console.log(deliveries.join(''), pickups.join(''));
        answer += curMove;
                
        for(let i = deliveries.length - 1; i >= 0 ; i--) {
            if(curCaps[0] === 0) {
                break;
            }
            
            if(curCaps[0] >= deliveries[i]) {
                curCaps[0] -= deliveries[i];
                deliveries.pop();
            } else {
                deliveries[i] -= curCaps[0];
                curCaps[0] = 0;
            }
        }
        
        for(let i = pickups.length - 1 ; i >= 0 ; i--) {
            if(curCaps[1] === 0) {
                break;
            }
            
            if(curCaps[1] >= pickups[i]) {
                curCaps[1] -= pickups[i];
                pickups.pop();
            } else {
                pickups[i] -= curCaps[1];
                curCaps[1] = 0;
            }
        }
        
             
    }
    
    return answer * 2;
}