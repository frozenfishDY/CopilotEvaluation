/**https://leetcode.com/problems/delete-columns-to-make-sorted-ii/ */
//You are given an array of n strings strs, all of the same length.
//We may choose any deletion indices, and we delete all the characters in those indices for each string.
//For example, if we have strs = ["abcdef","uvwxyz"] and deletion indices {0, 2, 3}, then the final array after deletions is ["bef", "vyz"].
//Suppose we chose a set of deletion indices answer such that after deletions, the final array has its elements in lexicographic order (i.e., strs[0] <= strs[1] <= strs[2] <= ... <= strs[n - 1]). Return the minimum possible value of answer.length.


/**
 * @param {string[]} strs
 * @return {number}
 */
var minDeletionSize = function(strs) {
    let n = strs.length;
    let m = strs[0].length;
    let result = 0;
    let dp = new Array(n).fill(0);
    for(let i = 0; i < m; i++){
        let temp = new Array(n).fill(0);
        for(let j = 0; j < n; j++){
            temp[j] = dp[j];
        }
        for(let j = 1; j < n; j++){
            if(strs[j][i] < strs[j - 1][i]){
                result++;
                break;
            }
            if(strs[j][i] > strs[j - 1][i]){
                temp[j] = Math.max(temp[j], dp[j - 1] + 1);
            }
        }
        dp = temp;
    }
    return result;
    
};

    