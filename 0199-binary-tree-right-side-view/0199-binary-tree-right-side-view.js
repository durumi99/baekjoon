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
 * @return {number[]}
 */
var rightSideView = function(root) {
    const answer = [];
    const dfs = (cur, depth) => {
        if(depth >= answer.length && cur !== null) {
            answer.push(cur.val);
        }

        if(cur?.right) dfs(cur.right, depth + 1);
        if(cur?.left) dfs(cur.left, depth + 1);
    };
    dfs(root, 0);
    return answer;
};