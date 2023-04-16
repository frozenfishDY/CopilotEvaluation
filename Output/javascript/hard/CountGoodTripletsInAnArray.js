/**https://leetcode.com/problems/count-good-triplets-in-an-array/ */
//You are given two 0-indexed arrays nums1 and nums2 of length n, both of which are permutations of [0, 1, ..., n - 1].
//A good triplet is a set of 3 distinct values which are present in increasing order by position both in nums1 and nums2. In other words, if we consider pos1v as the index of the value v in nums1 and pos2v as the index of the value v in nums2, then a good triplet will be a set (x, y, z) where 0 <= x, y, z <= n - 1, such that pos1x < pos1y < pos1z and pos2x < pos2y < pos2z.
//Return the total number of good triplets.


/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var goodTriplets = function(nums1, nums2) {
    let n = nums1.length;
    let ans = 0;
    for(let i = 0; i < n; i++){
        for(let j = i + 1; j < n; j++){
            for(let k = j + 1; k < n; k++){
                if(nums1[i] < nums1[j] && nums1[j] < nums1[k] && nums2[i] < nums2[j] && nums2[j] < nums2[k]){
                    ans++;
                }
            }
        }
    }
    return ans;
    
};

    