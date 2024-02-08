/**https://leetcode.com/problems/minimum-incompatibility/ */
//You are given an integer array nums and an integer k. You are asked to distribute this array into k subsets of equal size such that there are no two equal elements in the same subset.
//A subset's incompatibility is the difference between the maximum and minimum elements in that array.
//Return the minimum possible sum of incompatibilities of the k subsets after distributing the array optimally, or return -1 if it is not possible.
//A subset is a group integers that appear in the array with no particular order.


class MinimumIncompatibility {
    public int minimumIncompatibility(int[] nums, int k) {
        int n = nums.length;
        int m = n / k;
        int[] count = new int[17];
        for(int num : nums){
            count[num]++;
        }
        for(int i = 1; i <= 16; i++){
            if(count[i] > m){
                return -1;
            }
        }
        int[] dp = new int[1 << n];
        Arrays.fill(dp, -1);
        dp[0] = 0;
        for(int i = 1; i < (1 << n); i++){
            int[] freq = new int[17];
            int max = 0;
            int min = 17;
            for(int j = 0; j < n; j++){
                if(((i >> j) & 1) == 1){
                    freq[nums[j]]++;
                    max = Math.max(max, nums[j]);
                    min = Math.min(min, nums[j]);
                }
            }
            boolean valid = true;
            for(int j = 1; j <= 16; j++){
                if(freq[j] > 1){
                    valid = false;
                    break;
                }
            }
            if(valid){
                dp[i] = max - min;
            }
        }
        for(int i = 1; i < k; i++){
            for(int j = 0; j < (1 << n); j++){
                if(dp[j] != -1){
                    for(int l = j; l < (1 << n); l = (l + 1) | j){
                        if(dp[l] != -1){
                            dp[j | l] = Math.max(dp[j | l], dp[j] + dp[l]);
                        }
                    }
                }
            }
        }
        return dp[(1 << n) - 1];
        
    }
}
     
    