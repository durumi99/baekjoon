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
 */
var BSTIterator = function(root) {
    this.cur = -1;
    this.root = root;
};

/**
 * @return {number}
 */
BSTIterator.prototype.next = function() {
    const target = this.cur;
    let tmp = this.root;

    let next = this.root;
    while(tmp) {
        if(target >= tmp.val) {
            tmp = tmp.right;
        } else {
            next = tmp;
            tmp = tmp.left;
        }
    }
    console.log(target, next);
    this.cur = next.val;
    return next.val;
};

/**
 * @return {boolean}
 */
BSTIterator.prototype.hasNext = function() {
    const target = this.cur;
    let tmp = this.root;

    let next = false;
    while(tmp) {
        if(target >= tmp.val) {
            tmp = tmp.right;
        } else {
            next = tmp;
            tmp = tmp.left;
        }
    }
    console.log(next);
    return !!next;
};

/** 
 * Your BSTIterator object will be instantiated and called as such:
 * var obj = new BSTIterator(root)
 * var param_1 = obj.next()
 * var param_2 = obj.hasNext()
 */
