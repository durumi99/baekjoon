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
 * @return {void} Do not return anything, modify root in-place instead.
 */
var flatten = function(root) {
    if(!root) return root;
    const parseTree = (cur) => {
        if(!cur) return;
        console.log(cur);
        const left = cur?.left;
        const right = cur?.right;
        if(left) {  
            parseTree(left);
            cur.right = left;
            cur.left = null;
            let tmp = left;
            while(tmp.right) {
                tmp = tmp.right;
            }
            tmp.right = right;
        }

        if(right) 
            parseTree(cur.right);
    }

    parseTree(root);
};