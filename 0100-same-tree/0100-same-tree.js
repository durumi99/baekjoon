/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} p
 * @param {TreeNode} q
 * @return {boolean}
 */
var isSameTree = function(p, q) {
    const queueP = [];
    const queueQ = [];
    queueP.push(p);
    queueQ.push(q);
    
    while(queueP.length > 0) {
        const curP = queueP.shift();
        const curQ = queueQ.shift();
        if(curP === null && curQ === null) {
            continue;
        }
        if(curP?.val !== curQ?.val) {
            return false;
        }

        queueP.push(curP?.left);
        queueP.push(curP?.right);
        queueQ.push(curQ?.left);
        queueQ.push(curQ?.right);
    }

    return true;
};