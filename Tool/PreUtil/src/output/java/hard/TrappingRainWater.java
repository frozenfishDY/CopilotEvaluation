/**https://leetcode.com/problems/trapping-rain-water/ */
//Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.


class TrappingRainWater {
    public int trap(int[] height) {
        int n = height.length;
        int[] left = new int[n];
        int[] right = new int[n];
        int max = 0;
        for(int i = 0; i < n; i++){
            left[i] = max;
            max = Math.max(max, height[i]);
        }
        max = 0;
        for(int i = n - 1; i >= 0; i--){
            right[i] = max;
            max = Math.max(max, height[i]);
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            int min = Math.min(left[i], right[i]);
            if(min > height[i]) ans += min - height[i];
        }
        return ans;
        
    }
}
     
    