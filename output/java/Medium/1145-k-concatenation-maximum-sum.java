/**https://leetcode.com/problems/k-concatenation-maximum-sum/ */
//Given an integer array arr and an integer k, modify the array by repeating it k times.
//For example, if arr = [1, 2] and k = 3 then the modified array will be [1, 2, 1, 2, 1, 2].
//Return the maximum sub-array sum in the modified array. Note that the length of the sub-array can be 0 and its sum in that case is 0.
//As the answer can be very large, return the answer modulo 109 + 7.
// 
//Example 1:
//Input: arr = [1,2], k = 3
//Output: 9
//Example 2:
//Input: arr = [1,-2,1], k = 5
//Output: 2
//Example 3:
//Input: arr = [-1,-2], k = 7
//Output: 0
// 
//Constraints:
//	1 <= arr.length <= 105
//	1 <= k <= 105
//	-104 <= arr[i] <= 104
class Solution {
    public int kConcatenationMaxSum(int[] arr, int k) {
        int mod = 1000000007;
        int ans = 0;
        int sum = 0;
        int max = 0;
        int[] dp = new int[arr.length];
        for(int i = 0; i < arr.length; i++) {
            sum += arr[i];
            dp[i] = arr[i];
            if(i > 0 && dp[i-1] > 0) {
                dp[i] += dp[i-1];
            }
            max = Math.max(max, dp[i]);
        }
        if(k == 1) {
            return max;
        }
        for(int i = 0; i < arr.length; i++) {
            if(dp[i] < 0) {
                dp[i] = 0;
            }
            ans = Math.max(ans, dp[i]);
        }
        if(sum > 0) {
            ans += (k-2)*sum;
        }
        return ans % mod;
    }
}