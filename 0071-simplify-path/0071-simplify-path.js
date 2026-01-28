/**
 * @param {string} path
 * @return {string}
 */
var simplifyPath = function(path) {
    const tmp = path.split('/').filter(el => el !== '');
    
    const answer = tmp.reduce((acc, el, idx) => {
        if(el === '..') {
            acc.pop();
        } else if(el !== '.') {
            acc.push(el);
        }
        
        return acc;
    }, []);

    return '/' + answer.join('/');
};