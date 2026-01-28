/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

/**
 * @param {ListNode} head
 * @return {boolean}
 */
var hasCycle = function(head) {
    let cur = head;
    let cnt = 0;
    while(cur && cnt <= 10000) {
        cur = cur.next;
        cnt++;
    }

    return cnt > 10000;
};