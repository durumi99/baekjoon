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
 * @param {number} k
 * @return {number}
 */
var kthSmallest = function(root, k) {
    let answer = -1;
    const dfs = (cur) => {
        if(!cur) return;
        if(k <= 0) {
            return;
        }
        

        if(cur.left) dfs(cur.left);
        k--;
        if(k === 0) {
            answer = cur.val;
        }
        if(cur.right) dfs(cur.right);
    }
    
    dfs(root);    
    return answer;
};