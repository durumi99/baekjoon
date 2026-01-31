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
var getMinimumDifference = function(root) {
    const set = new Set();

    const traversal = (cur) => {
        if(!cur) {
            return;
        }

        set.add(Math.abs(cur.val));
        traversal(cur.left);
        traversal(cur.right);
    }

    traversal(root);
    const arr = [...set].sort((a, b) => a - b);
    let answer = Infinity;
    for(let i = 0 ; i < arr.length - 1 ; i++) {
        answer = Math.min(arr[i + 1] - arr[i], answer);
    }

    return answer;
};