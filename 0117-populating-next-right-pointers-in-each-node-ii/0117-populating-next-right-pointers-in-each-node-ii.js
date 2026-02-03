/**
 * // Definition for a _Node.
 * function _Node(val, left, right, next) {
 *    this.val = val === undefined ? null : val;
 *    this.left = left === undefined ? null : left;
 *    this.right = right === undefined ? null : right;
 *    this.next = next === undefined ? null : next;
 * };
 */

/**
 * @param {_Node} root
 * @return {_Node}
 */
var connect = function(root) {
    if(!root) {
        return root;
    }
    const q = [];
    q.push(root);

    while(q.length > 0) {
        const size = q.length;

        for(let i = 0 ; i < size ; i++) {
            const cur = q.shift();
        
            if(i !== size - 1) cur.next = q[0];
            if(cur.left) q.push(cur.left);
            if(cur.right) q.push(cur.right);           
        }
    }

    return root;
};