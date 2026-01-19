/**
 * @param {string} s
 * @param {string} t
 * @return {string}
 */
var minWindow = function(s, t) {
    const bucket = new Int32Array(128);
    let left=0,right=0;
    let min = Infinity;
    let haveCount=0;
    let needTotal=t.length;
    let startIndex = 0;
    for(let char of t){
        bucket[char.charCodeAt()]++;
    }

    while(right<s.length){
        let rc = s.charCodeAt(right);
        
        if(bucket[rc]>0){
            haveCount++;
        }
        bucket[rc]--;

        while(haveCount==needTotal){
            
            if(min>(right-left+1)){
                min=(right-left+1);
                startIndex=left;
            }
            
            let lc = s.charCodeAt(left);
            bucket[lc]++;
            if(bucket[lc]>0){
                haveCount--;
            }

            left++
        }
        
        right++;
    }    

    if(min == Infinity){
        return "";
    }

    return s.substring(startIndex,startIndex+min);

};