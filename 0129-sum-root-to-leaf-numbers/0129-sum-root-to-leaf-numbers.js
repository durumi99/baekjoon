/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var sumNumbers = function(root) {
    let sum = 0;
    const traversal = (cur, curSum) => {
        curSum += cur.val;
        const left = cur?.left;
        const right = cur?.right;
        
        if(!left && !right) {
            sum += +curSum;
            return;
        }
        if(left) traversal(cur.left, curSum);
        if(right) traversal(cur.right, curSum);        
    }

    traversal(root, "");
    return sum;
};