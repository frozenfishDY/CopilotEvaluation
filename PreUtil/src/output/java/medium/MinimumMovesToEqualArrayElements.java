/**https://leetcode.com/problems/minimum-moves-to-equal-array-elements/ */
//Given an integer array nums of size n, return the minimum number of moves required to make all array elements equal.
//In one move, you can increment n - 1 elements of the array by 1.


class MinimumMovesToEqualArrayElements {
    public int minMoves(int[] nums) {
        int n = nums.length;
        int min = Integer.MAX_VALUE;
        for(int i = 0; i < n; i++){
            min = Math.min(min, nums[i]);
        }
        int res = 0;
        for(int i = 0; i < n; i++){
            res += nums[i] - min;
        }
        return res;
        
    }
}

    