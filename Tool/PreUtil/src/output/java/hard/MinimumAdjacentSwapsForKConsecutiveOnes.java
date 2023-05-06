/**https://leetcode.com/problems/minimum-adjacent-swaps-for-k-consecutive-ones/ */
//You are given an integer array, nums, and an integer k. nums comprises of only 0's and 1's. In one move, you can choose two adjacent indices and swap their values.
//Return the minimum number of moves required so that nums has k consecutive 1's.


class MinimumAdjacentSwapsForKConsecutiveOnes {
    public int minMoves(int[] nums, int k) {
        int n = nums.length;
        int[] ones = new int[k];
        int idx = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == 1){
                ones[idx++] = i;
            }
        }
        int res = Integer.MAX_VALUE;
        int mid = k / 2;
        for(int i = 0; i < k - mid; i++){
            int cost = 0;
            for(int j = i; j < i + mid; j++){
                cost += ones[j + mid] - ones[j];
            }
            res = Math.min(res, cost);
        }
        return res;
        
    }
}
     
    