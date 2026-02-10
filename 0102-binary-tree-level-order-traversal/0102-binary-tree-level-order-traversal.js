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
 * @return {number[][]}
 */
var levelOrder = function(root) {
    if(!root) return [];
    const answer = [];
    const q = [];
    q.push(root);
    answer.push([root.val]);
    while(q.length > 0) {
        let tmp = [];
        const len = q.length;
        for(let i = 0 ; i < len ; i++) {
            const cur = q.shift();
            if(cur?.left) {
                tmp.push(cur.left.val);
                q.push(cur.left);
            }
            if(cur?.right) {
                tmp.push(cur.right.val);
                q.push(cur.right);
            }
        }
        if(tmp.length > 0)
            answer.push(tmp);
    }

    return answer;
};