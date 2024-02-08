/**https://leetcode.com/problems/number-of-ways-to-reorder-array-to-get-same-bst/ */
//Given an array nums that represents a permutation of integers from 1 to n. We are going to construct a binary search tree (BST) by inserting the elements of nums in order into an initially empty BST. Find the number of different ways to reorder nums so that the constructed BST is identical to that formed from the original array nums.
//For example, given nums = [2,1,3], we will have 2 as the root, 1 as a left child, and 3 as a right child. The array [2,3,1] also yields the same BST but [3,2,1] yields a different BST.
//Return the number of ways to reorder nums such that the BST formed is identical to the original BST formed from nums.
//Since the answer may be very large, return it modulo 10^9 + 7.


/**
 * @param {number[]} nums
 * @return {number}
 */
var numOfWays = function(nums) {
    let n = nums.length;
    let mod = 1000000007;
    let dp = new Array(n + 1).fill(0);
    dp[0] = 1;
    dp[1] = 1;
    for(let i = 2; i <= n; i++){
        dp[i] = (dp[i - 1] * (2 * i - 1)) % mod;
    }
    let res = 0;
    let dfs = (nums) => {
        if(nums.length <= 2){
            return 1;
        }
        let root = nums[0];
        let left = [];
        let right = [];
        for(let i = 1; i < nums.length; i++){
            if(nums[i] < root){
                left.push(nums[i]);
            }else{
                right.push(nums[i]);
            }
        }
        let leftSize = left.length;
        let rightSize = right.length;
        let leftWays = dfs(left);
        let rightWays = dfs(right);
        let totalWays = (dp[leftSize] * dp[rightSize]) % mod;
        let res = (totalWays * leftWays) % mod;
        res = (res * rightWays) % mod;
        return res;
    }
    res = dfs(nums);
    return res - 1;
    
};

    