/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} left
 * @param {number} right
 * @return {ListNode}
 */
var reverseBetween = function(head, left, right) {
    let cur = head;
    const map = new Map();
    const answer = new ListNode();
    let newCur = answer;
    let cnt = 1;

    while(cur) {
        if(cnt >= left && cnt <= right) {
            map.set(left + right - cnt, cur.val);
        } else {
            map.set(cnt, cur.val);
        }

        cur = cur.next;
        cnt++;
    }

    for (let i = 1 ; i < cnt ; i++) {
        newCur.next = new ListNode(map.get(i));
        newCur = newCur.next;
    }

    return answer.next;
};