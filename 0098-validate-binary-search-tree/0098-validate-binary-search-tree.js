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
 * @return {boolean}
 */
var isValidBST = function(root) {
    let answer = true;
    const arr = [];

    const dfs = (cur) => {
        if(!cur) return;
        if(!answer) return;
        if(cur.left) dfs(cur.left);
        if(arr.length === 0 || cur.val > arr.at(-1)) arr.push(cur.val);
        else answer = false;
        if(cur.right) dfs(cur.right);
    }
    
    dfs(root); 
    console.log(arr)
    return answer;
};