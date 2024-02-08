/**https://leetcode.com/problems/create-maximum-number/ */
//You are given two integer arrays nums1 and nums2 of lengths m and n respectively. nums1 and nums2 represent the digits of two numbers. You are also given an integer k.
//Create the maximum number of length k <= m + n from digits of the two numbers. The relative order of the digits from the same array must be preserved.
//Return an array of the k digits representing the answer.


/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @param {number} k
 * @return {number[]}
 */
var maxNumber = function(nums1, nums2, k) {
    let m = nums1.length;
    let n = nums2.length;
    let dp = [];
    for(let i = 0; i <= m; i++){
        dp.push([]);
        for(let j = 0; j <= n; j++){
            dp[i].push([]);
            for(let k = 0; k <= k; k++){
                dp[i][j].push([]);
                for(let l = 0; l <= k; l++){
                    dp[i][j][k].push(0);
                }
            }
        }
    }
    for(let i = 1; i <= m; i++){
        for(let j = 1; j <= n; j++){
            for(let k = 1; k <= k; k++){
                for(let l = 1; l <= k; l++){
                    if(i - j >= 0 && Math.abs(nums1[i - 1] - nums1[i - j - 1]) <= k){
                        dp[i][j][k][l] = true;
                    }
                    else{
                        dp[i][j][k][l] = dp[i - 1][j][k][l];
                    }
                }
            }
        }
    }
    return dp[m][n][k][k];
    
};

    