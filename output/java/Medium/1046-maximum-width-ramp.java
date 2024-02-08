/**https://leetcode.com/problems/maximum-width-ramp/ */
//A ramp in an integer array nums is a pair (i, j) for which i < j and nums[i] <= nums[j]. The width of such a ramp is j - i.
//Given an integer array nums, return the maximum width of a ramp in nums. If there is no ramp in nums, return 0.


class MaximumWidthRamp {
    public int maxWidthRamp(int[] nums) {
        int n = nums.length;
        int[] p = new int[n];
        for(int i = 0; i < n; i++){
            p[i] = i;
        }
        Arrays.sort(p, (a, b) -> nums[a] - nums[b]);
        int res = 0;
        int m = n;
        for(int i : p){
            res = Math.max(res, i - m);
            m = Math.min(m, i);
        }
        return res;
        
    }
}

    