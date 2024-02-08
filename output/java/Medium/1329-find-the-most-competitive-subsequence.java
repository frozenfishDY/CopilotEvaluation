/**https://leetcode.com/problems/find-the-most-competitive-subsequence/ */
//Given an integer array nums and a positive integer k, return the most competitive subsequence of nums of size k.
//An array's subsequence is a resulting sequence obtained by erasing some (possibly zero) elements from the array.
//We define that a subsequence a is more competitive than a subsequence b (of the same length) if in the first position where a and b differ, subsequence a has a number less than the corresponding number in b. For example, [1,3,4] is more competitive than [1,3,5] because the first position they differ is at the final number, and 4 is less than 5.


class FindTheMostCompetitiveSubsequence {
    public int[] mostCompetitive(int[] nums, int k) {
        int n = nums.length;
        int[] res = new int[k];
        int count = 0;
        for(int i = 0; i < n; i++){
            while(count > 0 && res[count - 1] > nums[i] && count + n - i > k){
                count--;
            }
            if(count < k){
                res[count++] = nums[i];
            }
        }
        return res;
        
    }
}
     
    