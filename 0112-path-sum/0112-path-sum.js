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
 * @param {number} targetSum
 * @return {boolean}
 */
var hasPathSum = function(root, targetSum) {
    if(!root) return false;

    const traversal = (cur, sum)=>{
        const left = cur?.left;
        const right = cur?.right;

        if(!left && !right) {
            return targetSum === sum + cur.val;
        }
        if(left && right) {
            return traversal(cur?.left, sum + cur.val) || traversal(cur?.right, sum + cur.val);
        }
        if(left) {
            return traversal(cur.left, sum + cur.val);
        }
        if(right) {
            return traversal(cur.right, sum + cur.val);
        }
    }

    return traversal(root, 0);
};