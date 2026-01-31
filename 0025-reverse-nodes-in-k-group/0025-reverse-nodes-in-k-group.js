/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} k
 * @return {ListNode}
 */
var reverseKGroup = function(head, k) {
    const dummyHead = new ListNode(0, head);
    let cur = dummyHead;
    while(cur) {
        let tmp = cur.next;
        let check = false;
        const arr = [];
        for(let i = 0 ; i < k ; i++) {
            if(!tmp) {
                check = true;
                break;
            }
            arr.push(tmp);
            tmp = tmp.next;
        }
        if(!check) {
            for(let i = k - 1 ; i >= 0; i--) {
                cur.next = arr[i];
                cur = cur.next;
            }
            cur.next = tmp;
        } 
        if(check) {
            break;
        }
    }


    return dummyHead.next;
};