function solution(num_list) {
    const tmp1 = num_list.at(-1);
    const tmp2 = num_list.at(-2);
    
    if(tmp1 > tmp2) {
        num_list.push(tmp1 - tmp2);
    } else {
        num_list.push(tmp1 * 2);
    }
    
    return num_list;
}