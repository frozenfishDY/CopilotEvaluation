/**https://leetcode.com/problems/distribute-repeating-integers/ */
//You are given an array of n integers, nums, where there are at most 50 unique values in the array. You are also given an array of m customer order quantities, quantity, where quantity[i] is the amount of integers the ith customer ordered. Determine if it is possible to distribute nums such that:
//The ith customer gets exactly quantity[i] integers,
//The integers the ith customer gets are all equal, and
//Every customer is satisfied.
//Return true if it is possible to distribute nums according to the above conditions.


class DistributeRepeatingIntegers {
    public boolean canDistribute(int[] nums, int[] quantity) {
        int n = nums.length;
        int m = quantity.length;
        int[] count = new int[51];
        for(int num : nums){
            count[num]++;
        }
        int[] freq = new int[51];
        for(int i = 1; i <= 50; i++){
            if(count[i] > 0){
                freq[count[i]]++;
            }
        }
        int[] dp = new int[10001];
        dp[0] = 1;
        for(int i = 1; i <= 50; i++){
            if(freq[i] > 0){
                for(int j = 10000; j >= i; j--){
                    if(dp[j - i] > 0){
                        dp[j] = Math.max(dp[j], dp[j - i] + freq[i] - 1);
                    }
                }
            }
        }
        for(int i = 0; i < m; i++){
            if(dp[quantity[i]] == 0){
                return false;
            }
        }
        return true;
        
    }
}
     
    