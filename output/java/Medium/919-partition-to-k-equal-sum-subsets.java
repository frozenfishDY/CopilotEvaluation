/**https://leetcode.com/problems/partition-to-k-equal-sum-subsets/ */
//Given an integer array nums and an integer k, return true if it is possible to divide this array into k non-empty subsets whose sums are all equal.
// 
//Example 1:
//Input: nums = [4,3,2,3,5,2,1], k = 4
//Output: true
//Explanation: It is possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.
//Example 2:
//Input: nums = [1,2,3,4], k = 3
//Output: false
// 
//Constraints:
//	1 <= k <= nums.length <= 16
//	1 <= nums[i] <= 104
//	The frequency of each element is in the range [1, 4].
class Solution {
    public boolean canPartitionKSubsets(int[] nums, int k) {
        int sum = 0;
        for(int num: nums) {
            sum += num;
        }
        if(sum % k != 0) {
            return false;
        }
        int target = sum / k;
        Arrays.sort(nums);
        int row = nums.length;
        int col = k;
        boolean[][] visited = new boolean[row][col];
        return dfs(nums, target, 0, 0, visited);
    }
    private boolean dfs(int[] nums, int target, int i, int sum, boolean[][] visited) {
        int row = nums.length;
        int col = visited[0].length;
        if(col == 1) {
            return true;
        }
        if(sum == target) {
            return dfs(nums, target, 0, 0, visited);
        }
        if(sum > target) {
            return false;
        }
        for(int j=i; j<row; j++) {
            if(visited[j][col-1]) {
                continue;
            }
            visited[j][col-1] = true;
            if(dfs(nums, target, j+1, sum+nums[j], visited)) {
                return true;
            }
            visited[j][col-1] = false;
        }
        return false;
    }
    }
