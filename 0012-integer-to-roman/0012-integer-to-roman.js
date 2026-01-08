/**
 * @param {number} num
 * @return {string}
 */
var intToRoman = function(num) {
    let str = "";

    while(num) {
        let value;
        let symbol;
        if (num >= 1000) {
            symbol = 'M';
            value = 1000;
        } else if (num >= 900) {
            symbol = 'CM';
            value = 900;
        } else if (num >= 500) {
            symbol = 'D';
            value = 500;
        } else if (num >= 400) {
            symbol = 'CD';
            value = 400;
        } else if (num >= 100) {
            symbol = 'C';
            value = 100;
        } else if (num >= 90) {
            symbol = 'XC';
            value = 90;
        } else if (num >= 50) {
            symbol = 'L';
            value = 50;
        } else if (num >= 40) {
            symbol = 'XL';
            value = 40;
        } else if (num >= 10) {
            symbol = 'X';
            value = 10;
        } else if (num >= 9) {
            symbol = 'IX';
            value = 9;
        } else if (num >= 5) {
            symbol = 'V';
            value = 5;
        } else if (num >= 4) {
            symbol = 'IV';
            value = 4;
        } else {
            symbol = 'I';
            value = 1;
        }

        str += symbol.repeat(~~(num / value));
        num %= value;
    }

    return str;
};