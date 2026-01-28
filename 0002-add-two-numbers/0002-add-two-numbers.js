/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2) {
    const append = (cur, val) => {
        // if(cur.val === 0) {
        //     cur.val = val;
        //     return;
        // }
        const newNode = new ListNode();
        newNode.val = val;
        cur.next = newNode;
    }
    let cur1 = l1;
    let cur2 = l2;
    const answer = new ListNode();
    let cur = answer;
    let cnt = 1;
    let num = 0;
    while(cur1 || cur2) {
        const tmp1 = cur1?.val || 0;
        const tmp2 = cur2?.val || 0;
        let tmp = num + tmp1 + tmp2;
        if(tmp >= 10) {
            num = 1;
            tmp -= 10;
        } else {
            num = 0;
        }
        append(cur, tmp);
        cur = cur.next;
        cur1 = cur1?.next;
        cur2 = cur2?.next;
        cnt *= 10;
    }

    if(num) {
        append(cur, num);
    }
    return answer.next;
};