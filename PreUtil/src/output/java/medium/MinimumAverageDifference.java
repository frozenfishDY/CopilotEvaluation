/**https://leetcode.com/problems/minimum-average-difference/ */
//You are given a 0-indexed integer array nums of length n.
//The average difference of the index i is the absolute difference between the average of the first i + 1 elements of nums and the average of the last n - i - 1 elements. Both averages should be rounded down to the nearest integer.
//Return the index with the minimum average difference. If there are multiple such indices, return the smallest one.
//Note:
//The absolute difference of two numbers is the absolute value of their difference.
//The average of n elements is the sum of the n elements divided (integer division) by n.
//The average of 0 elements is considered to be 0.


class MinimumAverageDifference {
    public int minimumAverageDifference(int[] nums) {
        int n = nums.length;
        int[] prefix = new int[n + 1];
        for(int i = 0; i < n; i++){
            prefix[i + 1] = prefix[i] + nums[i];
        }
        int res = 0;
        int min = Integer.MAX_VALUE;
        for(int i = 0; i < n - 1; i++){
            int left = prefix[i + 1];
            int right = prefix[n] - prefix[i + 1];
            int avg = (left + right) / (n - i - 1);
            int diff = Math.abs(avg - left / (i + 1));
            if(diff < min){
                min = diff;
                res = i;
            }
        }
        return res;
        
    }
}
     
    