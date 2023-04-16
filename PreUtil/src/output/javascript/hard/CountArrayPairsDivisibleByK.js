/**https://leetcode.com/problems/count-array-pairs-divisible-by-k/ */
//Given a 0-indexed integer array nums of length n and an integer k, return the number of pairs (i, j) such that:
//0 <= i < j <= n - 1 and
//nums[i] * nums[j] is divisible by k.


/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var countPairs = function(nums, k) {
    let n = nums.length;
    let count = 0;
    let map = new Map();
    for(let i = 0; i < n; i++){
        let rem = nums[i] % k;
        if(rem < 0){
            rem += k;
        }
        let req = (k - rem) % k;
        if(map.has(req)){
            count += map.get(req);
        }
        if(map.has(rem)){
            map.set(rem, map.get(rem) + 1);
        }else{
            map.set(rem, 1);
        }
    }
    return count;
    
};

    