/**https://leetcode.com/problems/minimum-moves-to-make-array-complementary/ */
//You are given an integer array nums of even length n and an integer limit. In one move, you can replace any integer from nums with another integer between 1 and limit, inclusive.
//The array nums is complementary if for all indices i (0-indexed), nums[i] + nums[n - 1 - i] equals the same number. For example, the array [1,2,3,4] is complementary because for all indices i, nums[i] + nums[n - 1 - i] = 5.
//Return the minimum number of moves required to make nums complementary.


class MinimumMovesToMakeArrayComplementary {
    public int minMoves(int[] nums, int limit) {
        int n = nums.length;
        int[] diff = new int[2 * limit + 2];
        for(int i = 0; i < n / 2; i++){
            int a = nums[i];
            int b = nums[n - 1 - i];
            diff[2] += 2;
            diff[Math.min(a, b) + 1]--;
            diff[a + b]--;
            diff[a + b + 1]++;
            diff[Math.max(a, b) + limit + 1]++;
        }
        int res = n;
        int curr = 0;
        for(int i = 2; i <= 2 * limit; i++){
            curr += diff[i];
            res = Math.min(res, curr);
        }
        return res;
        
    }
}
     
    