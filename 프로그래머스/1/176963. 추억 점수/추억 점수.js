function solution(name, yearning, photo) {
    var answer = photo.map((el) => {
       return el.reduce((acc, el) => {
           const idx = name.indexOf(el);
           if(idx !== -1) {
               acc += yearning[idx];
           }
           
           return acc;
       }, 0); 
    });
    return answer;
}