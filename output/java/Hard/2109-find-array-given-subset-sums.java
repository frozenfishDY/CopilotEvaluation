/**https://leetcode.com/problems/find-array-given-subset-sums/ */
//You are given an integer n representing the length of an unknown array that you are trying to recover. You are also given an array sums containing the values of all 2n subset sums of the unknown array (in no particular order).
//Return the array ans of length n representing the unknown array. If multiple answers exist, return any of them.
//An array sub is a subset of an array arr if sub can be obtained from arr by deleting some (possibly zero or all) elements of arr. The sum of the elements in sub is one possible subset sum of arr. The sum of an empty array is considered to be 0.
//Note: Test cases are generated such that there will always be at least one correct answer.


class FindArrayGivenSubsetSums {
    public int[] recoverArray(int n, int[] sums) {
        int[] res = new int[n];
        Arrays.sort(sums);
        int m = sums.length;
        int[] pre = new int[m];
        pre[0] = sums[0];
        for(int i = 1; i < m; i++){
            pre[i] = pre[i - 1] + sums[i];
        }
        int[] dp = new int[m];
        dp[0] = sums[0];
        for(int i = 1; i < m; i++){
            dp[i] = pre[i] - dp[i - 1];
        }
        int sum = dp[m - 1];
        int[] map = new int[sum + 1];
        for(int i = 0; i < m; i++){
            map[dp[i]] = sums[i];
        }
        int cur = 0;
        for(int i = n - 1; i >= 0; i--){
            res[i] = map[cur];
            cur += map[cur];
        }
        return res;
        
    }
}
     
    