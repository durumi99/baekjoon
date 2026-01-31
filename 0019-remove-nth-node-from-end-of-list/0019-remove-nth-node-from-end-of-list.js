/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} n
 * @return {ListNode}
 */
var removeNthFromEnd = function(head, n) {
    let cnt = 0;
    let cur = head;
    while(cur) {
        cur = cur.next;
        cnt++;
    }

    const dummyhead = new ListNode(0, head);
    let target = cnt - n;
    let prev = dummyhead;
    cur = head;
    
    while(target-- > 0) {
        cur = cur.next;
        prev = prev.next;
    }

    prev.next = cur.next;
    return dummyhead.next;
};