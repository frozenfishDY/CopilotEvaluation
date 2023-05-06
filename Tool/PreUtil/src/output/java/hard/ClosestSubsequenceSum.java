/**https://leetcode.com/problems/closest-subsequence-sum/ */
//You are given an integer array nums and an integer goal.
//You want to choose a subsequence of nums such that the sum of its elements is the closest possible to goal. That is, if the sum of the subsequence's elements is sum, then you want to minimize the absolute difference abs(sum - goal).
//Return the minimum possible value of abs(sum - goal).
//Note that a subsequence of an array is an array formed by removing some elements (possibly all or none) of the original array.


class ClosestSubsequenceSum {
    public int minAbsDifference(int[] nums, int goal) {
        int n = nums.length;
        int m = n / 2;
        int[] left = new int[1 << m];
        int[] right = new int[1 << (n - m)];
        for(int i = 0; i < (1 << m); i++){
            for(int j = 0; j < m; j++){
                if(((i >> j) & 1) == 1){
                    left[i] += nums[j];
                }
            }
        }
        for(int i = 0; i < (1 << (n - m)); i++){
            for(int j = 0; j < n - m; j++){
                if(((i >> j) & 1) == 1){
                    right[i] += nums[m + j];
                }
            }
        }
        Arrays.sort(left);
        Arrays.sort(right);
        int res = Integer.MAX_VALUE;
        for(int i = 0; i < (1 << m); i++){
            int idx = Arrays.binarySearch(right, goal - left[i]);
            if(idx >= 0){
                return 0;
            }
            idx = -idx - 1;
            if(idx < (1 << (n - m))){
                res = Math.min(res, Math.abs(goal - left[i] - right[idx]));
            }
            if(idx > 0){
                res = Math.min(res, Math.abs(goal - left[i] - right[idx - 1]));
            }
        }
        return res;
        
    }
}
     
    