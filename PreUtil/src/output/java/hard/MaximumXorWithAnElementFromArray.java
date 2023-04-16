/**https://leetcode.com/problems/maximum-xor-with-an-element-from-array/ */
//You are given an array nums consisting of non-negative integers. You are also given a queries array, where queries[i] = [xi, mi].
//The answer to the ith query is the maximum bitwise XOR value of xi and any element of nums that does not exceed mi. In other words, the answer is max(nums[j] XOR xi) for all j such that nums[j] <= mi. If all elements in nums are larger than mi, then the answer is -1.
//Return an integer array answer where answer.length == queries.length and answer[i] is the answer to the ith query.


class MaximumXorWithAnElementFromArray {
    public int[] maximizeXor(int[] nums, int[][] queries) {
        int n = nums.length;
        int m = queries.length;
        int[] ans = new int[m];
        Arrays.sort(nums);
        int[][] q = new int[m][3];
        for(int i = 0; i < m; i++){
            q[i][0] = queries[i][0];
            q[i][1] = queries[i][1];
            q[i][2] = i;
        }
        Arrays.sort(q, (a, b) -> a[1] - b[1]);
        int[] dp = new int[1 << 17];
        Arrays.fill(dp, -1);
        dp[0] = 0;
        for(int i = 1; i < (1 << 17); i++){
            int[] freq = new int[17];
            int max = 0;
            int min = 17;
            for(int j = 0; j < 17; j++){
                if(((i >> j) & 1) == 1){
                    freq[j]++;
                    max = Math.max(max, j);
                    min = Math.min(min, j);
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
        int j = 0;
        for(int i = 0; i < m; i++){
            while(j < n && nums[j] <= q[i][1]){
                j++;
            }
            if(j == 0){
                ans[q[i][2]] = -1;
            }
            else{
                int[] freq = new int[17];
                for(int k = 0; k < j; k++){
                    freq[nums[k]]++;
                }
                int mask = 0;
                for(int k = 16; k >= 0; k--){
                    if(freq[k] > 0){
                        mask |= (1 << k);
                    }
                }
                ans[q[i][2]] = dp[mask] ^ q[i][0];
            }
        }
        return ans;
        
    }
}
     
    