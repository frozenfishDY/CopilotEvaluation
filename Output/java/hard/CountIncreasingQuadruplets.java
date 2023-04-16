/**https://leetcode.com/problems/count-increasing-quadruplets/ */
//Given a 0-indexed integer array nums of size n containing all numbers from 1 to n, return the number of increasing quadruplets.
//A quadruplet (i, j, k, l) is increasing if:
//0 <= i < j < k < l < n, and
//nums[i] < nums[k] < nums[j] < nums[l].


class CountIncreasingQuadruplets {
    public long countQuadruplets(int[] nums) {
        int n = nums.length;
        long ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    for (int l = k + 1; l < n; l++) {
                        if (nums[i] < nums[k] && nums[k] < nums[j] && nums[j] < nums[l]) {
                            ans++;
                        }
                    }
                }
            }
        }
        return ans;
        
    }
}
     
    