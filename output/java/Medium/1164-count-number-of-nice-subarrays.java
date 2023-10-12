/**https://leetcode.com/problems/count-number-of-nice-subarrays/ */
//Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it._x000D_
//_x000D_
//Return the number of nice sub-arrays._x000D_
//_x000D_
// _x000D_
//Example 1:_x000D_
//_x000D_
//_x000D_
//Input: nums = [1,1,2,1,1], k = 3_x000D_
//Output: 2_x000D_
//Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1]._x000D_
//_x000D_
//_x000D_
//Example 2:_x000D_
//_x000D_
//_x000D_
//Input: nums = [2,4,6], k = 1_x000D_
//Output: 0_x000D_
//Explanation: There is no odd numbers in the array._x000D_
//_x000D_
//_x000D_
//Example 3:_x000D_
//_x000D_
//_x000D_
//Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2_x000D_
//Output: 16_x000D_
//_x000D_
//_x000D_
// _x000D_
//Constraints:_x000D_
//_x000D_
//_x000D_
//	1 <= nums.length <= 50000_x000D_
//	1 <= nums[i] <= 10^5_x000D_
//	1 <= k <= nums.length_x000D_
class Solution {
    public int numberOfSubarrays(int[] nums, int k) {
        int[] cnt = new int[nums.length+1];
        cnt[0] = 1;
        int odd = 0, ans = 0;
        for(int num: nums) {
            odd += num & 1;
            if(odd >= k) {
                ans += cnt[odd-k];
            }
            cnt[odd]++;
        }
        return ans;
    }
}