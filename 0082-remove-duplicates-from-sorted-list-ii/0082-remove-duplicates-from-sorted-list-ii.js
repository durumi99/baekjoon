/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var deleteDuplicates = function(head) {
    const map = new Map();
    const dummyHead = new ListNode(0, head);
    let cur = head;
    while(cur) {
        map.set(cur.val, (map.get(cur.val) || 0) + 1);
        cur = cur.next;
    }

    cur = dummyHead;
    let next = cur.next;
    while(next) {
        if(map.get(next.val) === 1) {
            cur.next = next;
            cur = cur.next;
        } 

        next = next.next;
    }
    cur.next = next;
    return dummyHead.next;
};