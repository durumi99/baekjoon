/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} list1
 * @param {ListNode} list2
 * @return {ListNode}
 */
var mergeTwoLists = function(list1, list2) {
    if(list1 === null) {
        return list2;
    }
    if(list2 === null) {
        return list1;
    }

    const answer = new ListNode(0);
    let cur = answer;
    while(list1 || list2) {
        const num1 = list1 ? list1.val : 101;
        const num2 = list2 ? list2.val : 101;
        if(num1 >= num2) {
            cur.next = new ListNode(num2);
            list2 = list2?.next;
        } else {
            cur.next = new ListNode(num1);
            list1 = list1?.next;
        }
        cur = cur.next;
    }

    return answer.next;
};