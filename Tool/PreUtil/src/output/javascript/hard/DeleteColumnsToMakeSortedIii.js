/**https://leetcode.com/problems/delete-columns-to-make-sorted-iii/ */
//You are given an array of n strings strs, all of the same length.
//We may choose any deletion indices, and we delete all the characters in those indices for each string.
//For example, if we have strs = ["abcdef","uvwxyz"] and deletion indices {0, 2, 3}, then the final array after deletions is ["bef", "vyz"].
//Suppose we chose a set of deletion indices answer such that after deletions, the final array has every string (row) in lexicographic order. (i.e., (strs[0][0] <= strs[0][1] <= ... <= strs[0][strs[0].length - 1]), and (strs[1][0] <= strs[1][1] <= ... <= strs[1][strs[1].length - 1]), and so on). Return the minimum possible value of answer.length.


/**
 * @param {string[]} strs
 * @return {number}
 */
var minDeletionSize = function(strs) {
    let dp = [];
    for(let i = 0; i <= strs.length; i++){
        dp.push([]);
        for(let j = 0; j <= strs[0].length; j++){
            dp[i].push(0);
        }
    }
    for(let i = 0; i <= strs.length; i++){
        dp[i][0] = 1;
    }
    for(let i = 1; i <= strs.length; i++){
        for(let j = 1; j <= strs[0].length; j++){
            if(i > j){
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    let ans = [];
    for(let i = 1; i <= strs[0].length; i++){
        ans.push(dp[strs.length][i] - dp[strs.length][i - 1]);
    }
    return ans;
    
};

    