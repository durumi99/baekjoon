/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} x
 * @return {ListNode}
 */
var partition = function(head, x) {
    if(!head || !head.next) {
        return head;
    }
    const dummyHead = new ListNode(0, head);
    let cur = dummyHead.next;
    let prev = dummyHead;
    let less = dummyHead;
    let check = false;

    while(cur) {
        if(cur.val >= x || !check) {
            if(cur.val >= x) check = true;
            else less = less.next;
            cur = cur.next;
            prev = prev.next;            
        } else {
            const nextNode = cur.next;
            
            cur.next = less.next;
            less.next = cur;
            less = less.next;
            
            prev.next = nextNode;
            cur = nextNode;
        }
    }

    return dummyHead.next;
};