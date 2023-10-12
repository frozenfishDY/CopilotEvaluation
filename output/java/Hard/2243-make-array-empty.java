/**https://leetcode.com/problems/make-array-empty/ */
//You are given an integer array nums containing distinct numbers, and you can perform the following operations until the array is empty:
//	If the first element has the smallest value, remove it
//	Otherwise, put the first element at the end of the array.
//Return an integer denoting the number of operations it takes to make nums empty.
// 
//Example 1:
//Input: nums = [3,4,-1]
//Output: 5
//	
//		
//			Operation
//			Array
//		
//	
//	
//		
//			1
//			[4, -1, 3]
//		
//		
//			2
//			[-1, 3, 4]
//		
//		
//			3
//			[3, 4]
//		
//		
//			4
//			[4]
//		
//		
//			5
//			[]
//		
//	
//Example 2:
//Input: nums = [1,2,4,3]
//Output: 5
//	
//		
//			Operation
//			Array
//		
//	
//	
//		
//			1
//			[2, 4, 3]
//		
//		
//			2
//			[4, 3]
//		
//		
//			3
//			[3, 4]
//		
//		
//			4
//			[4]
//		
//		
//			5
//			[]
//		
//	
//Example 3:
//Input: nums = [1,2,3]
//Output: 3
//	
//		
//			Operation
//			Array
//		
//	
//	
//		
//			1
//			[2, 3]
//		
//		
//			2
//			[3]
//		
//		
//			3
//			[]
//		
//	
// 
//Constraints:
//	1 <= nums.length <= 105
//	-109 <= nums[i] <= 109
//	All values in nums are distinct.
class Solution {
    public long countOperationsToEmptyArray(int[] nums) {
        int n = nums.length;
        int[] sorted = Arrays.copyOf(nums, n);
        Arrays.sort(sorted);
        int[] idx = new int[n];
        int[] cnt = new int[n];
        for (int i = 0; i < n; ++i) {
            idx[i] = Arrays.binarySearch(sorted, nums[i]);
            cnt[i] = 1;
        }
        int[] dp = new int[n];
        Arrays.fill(dp, Integer.MAX_VALUE);
        for (int i = 0; i < n; ++i) {
            int j = idx[i];
            dp[j] = Math.min(dp[j], cnt[i]);
            if (j > 0) {
                cnt[j - 1] += cnt[i];
            }
            if (j < n - 1) {
                cnt[j + 1] += cnt[i];
            }
        }
        long ans = 0;
        for (int i = 0; i < n; ++i) {
            if (dp[i] != Integer.MAX_VALUE) {
                ans += dp[i];
            }
        }
        return ans;
    }
}