/**
 * @param {string} s
 * @return {number}
 */
var romanToInt = function(s) {
    const map = new Map();
    map.set('I', 1);
    map.set('V', 5);
    map.set('X', 10);
    map.set('L', 50);
    map.set('C', 100);
    map.set('D', 500);
    map.set('M', 1000);
    
    map.set('IV', 4);
    map.set('IX', 9);
    map.set('XL', 40);
    map.set('XC', 90);
    map.set('CD', 400);
    map.set('CM', 900);

    let sum = 0;
    const arr = [...s];
    const len = arr.length;

    for(let i = 0 ; i < len ; i++) {
        if(i < len && map.has(arr[i] + arr[i + 1])) {
            sum += map.get(arr[i] + arr[i + 1]);
            i++;
        } else {
            sum += map.get(arr[i]);
        }
    }

    return sum;
};