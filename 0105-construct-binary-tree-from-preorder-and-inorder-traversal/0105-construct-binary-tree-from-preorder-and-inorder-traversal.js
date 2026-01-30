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
    let index = 0;
    const dfs = (left, right) => {
        if(left > right) {
            return null;
        }
        
        const rootVal = preorder[index++];
        const root = new TreeNode(rootVal);
        const mid = inorder.indexOf(rootVal);

        root.left = dfs(left, mid - 1);
        root.right = dfs(mid + 1, right);

        return root;
    }

    return dfs(0, preorder.length - 1);
};