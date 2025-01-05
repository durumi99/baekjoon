function solution(coin, cards) {
    var answer = 1;
    let curCard = new Set();
    let thrownCard = new Set();
    const n = cards.length;
    
    cards.some((card, idx) => {
        if(idx < n / 3) {
            curCard.add(card);
        } else if (idx % 2 === 0) {
            // console.log(answer, coin);
            // console.log(curCard);
            // console.log(thrownCard);
            
            thrownCard.add(card);
            thrownCard.add(cards[idx + 1]);

            let check = false;

            curCard.forEach((val1) => {
                if(check) {
                    return;
                }
                curCard.forEach((val2) => {
                    if(val1 + val2 === n + 1) {
                        // console.log('curCard2', val1, val2);
                        curCard.delete(val1);
                        curCard.delete(val2);
                        check = true;
                    } 
                });
            });
            
            if(check) {
                answer++;
                return false;
            }
            
            curCard.forEach((val1) => {
                if(check) {
                    return;
                }
                thrownCard.forEach((val2) => {
                    if(val1 + val2 === n + 1 && coin > 0) {
                        // console.log('curCard & thrownCard', val1, val2);
                        curCard.delete(val1);
                        thrownCard.delete(val2);
                        coin--;
                        check = true;
                    } 
                })
            });
            
            if(check) {
                answer++;
                return false;
            }
            
            thrownCard.forEach((val1) => {
                if(check) {
                    return;
                }
                thrownCard.forEach((val2) => {
                    if(val1 + val2 === n + 1 && coin >= 2) {
                        // console.log('thrownCard2', val1, val2);
                        thrownCard.delete(val1);
                        thrownCard.delete(val2);
                        coin -= 2;
                        check = true;
                    } 
                })
            });
            
            if(check) {
                answer++;
                return false;
            }
            
            console.log('gg');
            return true;
        }
    })
    return answer;
}