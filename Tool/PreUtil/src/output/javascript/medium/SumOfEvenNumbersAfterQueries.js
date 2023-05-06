/**https://leetcode.com/problems/sum-of-even-numbers-after-queries/ */
//You are given an integer array nums and an array queries where queries[i] = [vali, indexi].
//For each query i, first, apply nums[indexi] = nums[indexi] + vali, then print the sum of the even values of nums.
//Return an integer array answer where answer[i] is the answer to the ith query.


/**
 * @param {number[]} nums
 * @param {number[][]} queries
 * @return {number[]}
 */
var sumEvenAfterQueries = function(nums, queries) {
    let sum = 0;
    for(let i = 0; i < nums.length; i++){
        if(nums[i] % 2 == 0){
            sum += nums[i];
        }
    }
    let ans = [];
    for(let i = 0; i < queries.length; i++){
        let val = queries[i][0];
        let index = queries[i][1];
        if(nums[index] % 2 == 0){
            sum -= nums[index];
        }
        nums[index] += val;
        if(nums[index] % 2 == 0){
            sum += nums[index];
        }
        ans.push(sum);
    }
    return ans;
    
};

    