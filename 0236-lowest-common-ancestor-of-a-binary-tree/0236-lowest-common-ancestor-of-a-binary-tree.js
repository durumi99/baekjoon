/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @param {TreeNode} p
 * @param {TreeNode} q
 * @return {TreeNode}
 */
var lowestCommonAncestor = function(root, p, q) {
    let answer = root;
    
    const traversal = (cur, foundP, foundQ) => {
        if(!cur) return [foundP, foundQ];
        const nextP = foundP || cur === p;
        const nextQ = foundQ || cur === q;
        if(nextP && nextQ) {
            return [true, true];
        }

        const leftResult = traversal(cur.left, nextP, nextQ);
        const rightResult = traversal(cur.right, nextP, nextQ);
        const result = [leftResult[0] || rightResult[0], leftResult[1] || rightResult[1]];
        
        if(answer !== root) {
            return result;
        }
        if((cur === p || cur === q) && (result[0] && result[1])) {
            answer = cur;
        }

        if(leftResult[0] !== rightResult[0] && leftResult[1] !== rightResult[1]) {
            answer = cur;
        }

        return result;
    };

    traversal(root, false, false);
    return answer;
};