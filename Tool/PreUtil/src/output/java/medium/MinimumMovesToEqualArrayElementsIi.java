/**https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/ */
//Given an integer array nums of size n, return the minimum number of moves required to make all array elements equal.
//In one move, you can increment or decrement an element of the array by 1.
//Test cases are designed so that the answer will fit in a 32-bit integer.


class MinimumMovesToEqualArrayElementsIi {
    public int minMoves2(int[] nums) {
        int n = nums.length;
        Arrays.sort(nums);
        int res = 0;
        int i = 0;
        int j = n - 1;
        while(i < j){
            res += nums[j] - nums[i];
            i++;
            j--;
        }
        return res;
        
    }
}

    