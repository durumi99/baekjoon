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
var countNodes = function(root) {
    if(!root) return 0;
    let cnt = 0;
    let q =[];
    q.push(root);

    while(q.length > 0) {
        const cur = q.shift();
        cnt++;
        cur.left && q.push(cur.left);
        cur.right && q.push(cur.right);
    } 

    return cnt;
};