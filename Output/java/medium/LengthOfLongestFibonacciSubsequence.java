/**https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/ */
//A sequence x1, x2, ..., xn is Fibonacci-like if:
//n >= 3
//xi + xi+1 == xi+2 for all i + 2 <= n
//Given a strictly increasing array arr of positive integers forming a sequence, return the length of the longest Fibonacci-like subsequence of arr. If one does not exist, return 0.
//A subsequence is derived from another sequence arr by deleting any number of elements (including none) from arr, without changing the order of the remaining elements. For example, [3, 5, 8] is a subsequence of [3, 4, 5, 6, 7, 8].


class LengthOfLongestFibonacciSubsequence {
    public int lenLongestFibSubseq(int[] arr) {
        int n = arr.length;
        int[][] dp = new int[n][n];
        int res = 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int left = 0;
                int right = i;
                while(left < right){
                    int mid = left + (right - left) / 2;
                    if(arr[mid] + arr[i] == arr[j]){
                        left = mid + 1;
                    }else if(arr[mid] + arr[i] < arr[j]){
                        left = mid + 1;
                    }else{
                        right = mid;
                    }
                }
                if(left == i){
                    dp[i][j] = 0;
                }else{
                    dp[i][j] = dp[left][i] + 1;
                    res = Math.max(res, dp[i][j]);
                }
            }
        }
        return res == 0 ? 0 : res + 2;
        
        
    }
}

    