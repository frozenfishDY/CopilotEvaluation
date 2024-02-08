/**https://leetcode.com/problems/make-array-strictly-increasing/ */
//Given two integer arrays arr1 and arr2, return the minimum number of operations (possibly zero) needed to make arr1 strictly increasing.
//In one operation, you can choose two indices 0 <= i < arr1.length and 0 <= j < arr2.length and do the assignment arr1[i] = arr2[j].
//If there is no way to make arr1 strictly increasing, return -1.
// 
//Example 1:
//Input: arr1 = [1,5,3,6,7], arr2 = [1,3,2,4]
//Output: 1
//Explanation: Replace 5 with 2, then arr1 = [1, 2, 3, 6, 7].
//Example 2:
//Input: arr1 = [1,5,3,6,7], arr2 = [4,3,1]
//Output: 2
//Explanation: Replace 5 with 3 and then replace 3 with 4. arr1 = [1, 3, 4, 6, 7].
//Example 3:
//Input: arr1 = [1,5,3,6,7], arr2 = [1,6,3,3]
//Output: -1
//Explanation: You can't make arr1 strictly increasing.
// 
//Constraints:
//	1 <= arr1.length, arr2.length <= 2000
//	0 <= arr1[i], arr2[i] <= 10^9
// 
/**
 * @param {number[]} arr1
 * @param {number[]} arr2
 * @return {number}
 */
var makeArrayIncreasing = function(arr1, arr2) {
    arr2 = [...new Set(arr2)].sort((a, b) => a - b);
    let len1 = arr1.length;
    let len2 = arr2.length;
    let dp = new Array(len1 + 1);
    for (let i = 0; i <= len1; i++) {
        dp[i] = new Array(len2 + 1).fill(Number.MAX_SAFE_INTEGER);
    }
    dp[0][0] = Number.MIN_SAFE_INTEGER;
    for (let i = 1; i <= len1; i++) {
        for (let j = 0; j <= len2; j++) {
            if (arr1[i - 1] > dp[i - 1][j]) {
                dp[i][j] = arr1[i - 1];
            }
            if (j > 0 && arr2[j - 1] > dp[i - 1][j - 1]) {
                dp[i][j] = Math.min(dp[i][j], arr2[j - 1]);
            }
            if (i === len1 && dp[i][j] !== Number.MAX_SAFE_INTEGER) {
                return j;
            }
        }
    }
    return -1;
};