function solution(arr) {
    var answer = [0, 0];
    let cur = arr.length;
    let visited = new Array(arr.length).fill(new Array(arr.length).fill(0));
    
    while(true) {
        for(let i = 0 ; i < arr.length ; i += cur) {
            for(let j = 0 ; j < arr.length ; j += cur) {
                if(arr[i][j] == -1)
                    continue;
                if(checkArea(arr, i, j, cur)) {
                    answer[arr[i][j]]++;
                    setArea(arr, i, j, cur);
                    // for(let k = i ; k < i + cur ; k++) {
                    //     for(let l = j ; k < j + cur ; l++) {
                    //         arr[k][l] = -1;
                    //     }
                    // }
                }
            }
        }
        // console.log(arr);
        if(cur == 1) {
            break;
        }
        
        cur /= 2;
    }
    return answer;
}

function checkArea(arr, y, x, cur) {
    const num = arr[y][x];
    for(let i = y ; i < y + cur ; i++) {
        for(let j = x ; j < x + cur ; j++) {
            if(arr[i][j] != num) {
                 return false;
            }
        }
    }
    
    return true;
}

function setArea(arr, y, x, cur) {
    for(let i = y ; i < y + cur ; i++) {
        for(let j = x ; j < x + cur ; j++) {
            arr[i][j] = -1;
        }
    }
}
