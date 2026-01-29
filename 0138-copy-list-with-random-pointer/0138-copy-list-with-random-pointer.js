/**
 * // Definition for a _Node.
 * function _Node(val, next, random) {
 *    this.val = val;
 *    this.next = next;
 *    this.random = random;
 * };
 */

/**
 * @param {_Node} head
 * @return {_Node}
 */
var copyRandomList = function(head) {
    const newHead = new _Node();
    let cur = head;
    let newCur = newHead;

    while(cur) {
        newCur.next = new _Node(cur.val);
        newCur = newCur.next;
        cur = cur.next;
    }

    const getRandom = (target) => {
        let cur = head;
        let newCur = newHead.next;
        
        while(cur) {
            if(cur === target){
                break;
            }
            cur = cur.next;
            newCur = newCur.next;
        }

        return newCur;
    };

    cur = head;
    newCur = newHead.next;
    while(cur) {
        const target = cur.random;
        if(target !== null) {
            newCur.random = getRandom(target);
        }

        cur = cur.next;
        newCur = newCur.next; 
    }

    return newHead.next;
};