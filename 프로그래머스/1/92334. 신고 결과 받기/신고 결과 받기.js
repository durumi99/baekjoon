function solution(id_list, report, k) {
    var answer = new Array(id_list.length).fill(0)
    let report_arr = Array.from(new Array(id_list.length), () => new Array(id_list.length).fill(0));
    
    const id_map = id_list.reduce((map, id, idx) => {
        map.set(id, idx);
        return map;
    }, new Map);
    
    report.forEach((string) => {
        const [id1, id2] = string.split(' ');
        report_arr[id_map.get(id2)][id_map.get(id1)] = 1;
    })
    
    report_arr.forEach((arr, idx) => {
        let reporter = [];
        const sum = arr.reduce((cum, val, idx) => {
            if(val === 1) {
                cum++;
                reporter.push(idx);
            }
            return cum;
        }, 0);
        
        if (sum >= k) {
            reporter.forEach((el) => {
                answer[el]++;
            })
        }
    })
    
    return answer;
}