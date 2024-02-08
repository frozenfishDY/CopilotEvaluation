/**https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/ */
//You may recall that an array arr is a mountain array if and only if:
//arr.length >= 3
//There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
//arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
//arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
//Given an integer array nums, return the minimum number of elements to remove to make nums a mountain array.


class MinimumNumberOfRemovalsToMakeMountainArray {
    public int minimumMountainRemovals(int[] nums) {
        int n = nums.length;
        int[] lis = new int[n];
        int[] lds = new int[n];
        Arrays.fill(lis, 1);
        Arrays.fill(lds, 1);
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    lis[i] = Math.max(lis[i], lis[j] + 1);
                }
            }
        }
        for(int i = n - 2; i >= 0; i--){
            for(int j = n - 1; j > i; j--){
                if(nums[i] > nums[j]){
                    lds[i] = Math.max(lds[i], lds[j] + 1);
                }
            }
        }
        int res = 0;
        for(int i = 1; i < n - 1; i++){
            if(lis[i] > 1 && lds[i] > 1){
                res = Math.max(res, lis[i] + lds[i] - 1);
            }
        }
        return n - res;
        
    }
}
     
    