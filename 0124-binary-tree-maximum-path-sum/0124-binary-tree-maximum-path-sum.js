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
var maxPathSum = function(root) {
    let answer = -Infinity;

    const traversal = (cur) => {
        const left = cur?.left;
        const right = cur?.right;
        const leftSum = left ? Math.max(traversal(cur.left), 0) : 0;
        const rightSum = right ? Math.max(traversal(cur.right), 0) : 0;
        const curSum = cur.val + leftSum + rightSum;

        answer = Math.max(cur.val, curSum,  answer);
        return Math.max(leftSum, rightSum) + cur.val;
    }

    traversal(root);
    return answer;
};