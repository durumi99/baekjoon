/**
 * @param {number[]} nums1
 * @param {number} m
 * @param {number[]} nums2
 * @param {number} n
 * @return {void} Do not return anything, modify nums1 in-place instead.
 */
var merge = function(nums1, m, nums2, n) {
    let idx1 = 0;
    let idx2 = 0;

    while(idx2 < n) {
        const cur1 = nums1[idx1];
        const cur2 = nums2[idx2];
        
        if(cur1 >= cur2 || (cur1 === 0 && idx1 >= m + idx2)) {
            nums1.splice(idx1, 0, cur2);
            idx2++;
            nums1.pop();
        } else {
            idx1++;
        }

    }
};