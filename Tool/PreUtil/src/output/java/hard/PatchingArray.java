/**https://leetcode.com/problems/patching-array/ */
//Given a sorted integer array nums and an integer n, add/patch elements to the array such that any number in the range [1, n] inclusive can be formed by the sum of some elements in the array.
//Return the minimum number of patches required.


class PatchingArray {
    public int minPatches(int[] nums, int n) {
        int patches = 0, i = 0;
        long miss = 1;
        while (miss <= n) {
            if (i < nums.length && nums[i] <= miss) {
                miss += nums[i++];
            } else {
                miss += miss;
                patches++;
            }
        }
        return patches;
        
    }
}
     
    