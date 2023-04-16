/**https://leetcode.com/problems/longest-turbulent-subarray/ */
//Given an integer array arr, return the length of a maximum size turbulent subarray of arr.
//A subarray is turbulent if the comparison sign flips between each adjacent pair of elements in the subarray.
//More formally, a subarray [arr[i], arr[i + 1], ..., arr[j]] of arr is said to be turbulent if and only if:
//For i <= k < j:
//arr[k] > arr[k + 1] when k is odd, and
//arr[k] < arr[k + 1] when k is even.
//Or, for i <= k < j:
//arr[k] > arr[k + 1] when k is even, and
//arr[k] < arr[k + 1] when k is odd.


class LongestTurbulentSubarray {
    public int maxTurbulenceSize(int[] arr) {
        int n = arr.length;
        int[] dp = new int[n];
        Arrays.fill(dp, 1);
        int max = 1;
        for(int i = 1; i < n; i++){
            if(i % 2 == 0){
                if(arr[i] > arr[i - 1]){
                    dp[i] = dp[i - 1] + 1;
                }
            }else{
                if(arr[i] < arr[i - 1]){
                    dp[i] = dp[i - 1] + 1;
                }
            }
            max = Math.max(max, dp[i]);
        }
        Arrays.fill(dp, 1);
        for(int i = 1; i < n; i++){
            if(i % 2 == 0){
                if(arr[i] < arr[i - 1]){
                    dp[i] = dp[i - 1] + 1;
                }
            }else{
                if(arr[i] > arr[i - 1]){
                    dp[i] = dp[i - 1] + 1;
                }
            }
            max = Math.max(max, dp[i]);
        }
        return max;
        
    }
}

    