/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {number[]} inorder
 * @param {number[]} postorder
 * @return {TreeNode}
 */
var buildTree = function(inorder, postorder) {
    const map = new Map()
    for (let i = 0; i < inorder.length; i++) {
        map.set(inorder[i], i)
    }
    let postIndx = postorder.length -1;
    const traverse = (l, r) => {
        if (l > r) return null;
        const rootVal = postorder[postIndx--];
        let root = new TreeNode(rootVal);
        let mid = map.get(rootVal)

        root.right = traverse(mid + 1, r)
        root.left = traverse(l, mid - 1)

        return root
    }

    return traverse(0, postorder.length - 1);
};