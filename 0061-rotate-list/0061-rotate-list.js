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
var rotateRight = function(head, k) {
    if(!k || !head || !head.next) {
        return head;
    }

    const dummyHead = new ListNode(0, head);
    let cnt = 0;
    let cur = dummyHead.next;
    while(cur) {
        cur = cur.next;
        cnt++;
    }
    if(k % cnt === 0) {
        return head;
    }
    const target = cnt - (k % cnt);
    console.log(target)
    cur = dummyHead.next;
    let prev = dummyHead;
    for(let i = 0 ; i < target ; i++) {
        cur = cur.next;
        prev = prev.next;
    }
    prev.next = null;
    
    const newHead = cur;
    while(cur.next) {
        cur = cur.next;
    }
    cur.next = dummyHead.next;
    dummyHead.next = newHead;

    return dummyHead.next;
};