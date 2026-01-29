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
var maxDepth = function(root) {
    if(!root){
        return 0;
    }
    let answer = 1;

    const dfs = (cur, cnt) => {
        if(!cur.left && !cur.right) {
            answer = Math.max(answer, cnt);
            return;
        }

        if (cur.left) dfs(cur.left, cnt + 1);
        if (cur.right) dfs(cur.right, cnt + 1);
    }

    dfs(root, 1);
    return answer;
};