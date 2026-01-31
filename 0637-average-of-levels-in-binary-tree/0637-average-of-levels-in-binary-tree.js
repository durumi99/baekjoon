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

var averageOfLevels = function(root) {
    const answer = [];
    const q = [];
    q.push([root, 0]);
    while(q.length > 0) {
        const cur = q.shift();
        const node = cur[0];
        const level = cur[1];
        if(answer[level] === undefined) {
            answer.push([node.val]);
        } else {
            answer[level].push(node.val); 
        }
        if(node.left) {
            q.push([node.left, level + 1]);
        }
        if(node.right) {
            q.push([node.right, level + 1]);
        }
    }
    
    return answer.map((arr) => {
        return arr.reduce((acc, el) => {
            return acc + el;
        }, 0) / arr.length;
    });
};