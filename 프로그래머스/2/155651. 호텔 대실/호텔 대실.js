function solution(book_time) {
    var answer = [];
    book_time.sort();
    
    book_time.forEach((el) => {
        const startTime = format(el[0]);
        const endTime = format(el[1]) + 10;
        let check = true;
        
        answer.some((el2) => {
            if(el2.endTime <= startTime) {
                el2.endTime = endTime;
                check = false;
                return true;
            }
        });
    
        if(check) {
            answer.push({startTime : startTime, endTime : endTime});
        }
    });
    
    return answer.length;
}

function format(s) {
    return Number(s.slice(0, 2)) * 60 + Number(s.slice(3, 5));
}