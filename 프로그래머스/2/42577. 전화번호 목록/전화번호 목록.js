function solution(phone_book) {
    var answer = true;
    let phone_book_set = new Set();
    
    phone_book.sort().forEach((el, idx) => {
        el.split('').reduce((acc, c) => {
            acc += c;
            if(phone_book_set.has(acc)) {
                return answer = false;
            }
            
            return acc;
        }, '');
        
        phone_book_set.add(el);
    });
                       
    return answer;
}