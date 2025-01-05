function solution(today, terms, privacies) {
    var answer = [];
    const termsMap = new Map();
    terms.forEach((term) => {
        const tmp = term.split(' ');
        termsMap.set(tmp[0], tmp[1]);
    })
    
    
    const expiredDates = privacies.map((privacy) => {
        const tmp = privacy.split(' ');
        let date = tmp[0].split('.');
        const term = termsMap.get(tmp[1]);
        
        date[1] = ~~date[1] + ~~term;
        if(date[1] > 12) {
            date[0] = ~~date[0] + Math.floor(date[1] / 12);
            date[1] %= 12;
            if(date[1] == 0) {
                date[0]--;
                date[1] = 12;
            }
        }
        
        if(date[1] < 10) {
            date[1] = '0' + date[1].toString();
        } 
        
        return date.join('.');
    })
    console.log(expiredDates);
    expiredDates.forEach((date, idx) => {
        if(today >= date) {
            answer.push(idx + 1);
        }
    })
    
    return answer;
}