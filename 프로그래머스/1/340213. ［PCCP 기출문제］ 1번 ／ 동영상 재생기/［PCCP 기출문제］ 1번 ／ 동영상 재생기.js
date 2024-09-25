let VIDEOLEN;
let op_start, op_end;
let current;

function prev(current) {
    return current - 10 >= 0 ? current - 10 : 0;
}

function next(current) {
    return current + 10 <= VIDEOLEN ? current + 10 : VIDEOLEN;
}

function passOpening(current) {
    if (op_start <= current && current <= op_end) {
        return op_end;
    }
    
    return current;
}


function solution(video_len, pos, _op_start, _op_end, commands) {
    VIDEOLEN = video_len.substring(0, 2) * 60 + video_len.substring(3, 5) * 1;
    current = pos.substring(0, 2) * 60 + pos.substring(3, 5) * 1;
    op_start = _op_start.substring(0, 2) * 60 + _op_start.substring(3, 5) * 1;
    op_end = _op_end.substring(0, 2) * 60 + _op_end.substring(3, 5) * 1;
        
    var answer = '';
    for(let command of commands) {
        current = passOpening(current);
        if (command === "prev") {
            current = prev(current);
        } else if (command === "next") {
            current = next(current);
        }
        
    }
    current = passOpening(current);
    
    let min = Math.floor(current / 60);
    if(min < 10) {
        answer += '0';
    }
    answer += min + ':';
    
    let sec = current % 60;
    if(sec < 10) {
        answer += '0';
    }
    answer += sec;
    
    return answer;
}