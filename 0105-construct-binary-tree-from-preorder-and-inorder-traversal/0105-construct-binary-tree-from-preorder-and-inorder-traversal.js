/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {number[]} preorder
 * @param {number[]} inorder
 * @return {TreeNode}
 */
var buildTree = function(preorder, inorder) {
    const tree = new TreeNode(preorder[0]);
    
    const dfs = (cur, curPreorder, curInorder) => {
        const rootIndex = curInorder.indexOf(curPreorder[0]);
        cur.val = curPreorder[0];
        if(curPreorder.length === 1 || rootIndex === -1) {
            return;
        }
        
        const left = curInorder.slice(0, rootIndex);
        const right = curInorder.slice(rootIndex + 1);
        if(left.length) {
            cur.left = new TreeNode();
            dfs(cur.left, curPreorder.slice(1, left.length + 1), left);
        }
        if(right.length) {
            cur.right = new TreeNode();
            dfs(cur.right, curPreorder.slice(1 + left.length), right);
        }
    }
    dfs(tree, preorder, inorder);
    
    return tree;
};