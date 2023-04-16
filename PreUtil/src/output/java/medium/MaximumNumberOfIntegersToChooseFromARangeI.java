/**https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-i/ */
//You are given an integer array banned and two integers n and maxSum. You are choosing some number of integers following the below rules:
//The chosen integers have to be in the range [1, n].
//Each integer can be chosen at most once.
//The chosen integers should not be in the array banned.
//The sum of the chosen integers should not exceed maxSum.
//Return the maximum number of integers you can choose following the mentioned rules.


class MaximumNumberOfIntegersToChooseFromARangeI {
    public int maxCount(int[] banned, int n, int maxSum) {
        int[] prefix = new int[n + 1];
        for(int i : banned){
            prefix[i]++;
        }
        for(int i = 1; i <= n; i++){
            prefix[i] += prefix[i - 1];
        }
        int res = 0;
        for(int i = 1; i <= n; i++){
            int j = Math.min(n, maxSum - i);
            if(prefix[j] - prefix[i - 1] == 0){
                res = Math.max(res, j - i + 1);
            }
        }
        return res;
        
    }
}

    