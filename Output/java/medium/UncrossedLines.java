/**https://leetcode.com/problems/uncrossed-lines/ */
//You are given two integer arrays nums1 and nums2. We write the integers of nums1 and nums2 (in the order they are given) on two separate horizontal lines.
//We may draw connecting lines: a straight line connecting two numbers nums1[i] and nums2[j] such that:
//nums1[i] == nums2[j], and
//the line we draw does not intersect any other connecting (non-horizontal) line.
//Note that a connecting line cannot intersect even at the endpoints (i.e., each number can only belong to one connecting line).
//Return the maximum number of connecting lines we can draw in this way.


class UncrossedLines {
    public int maxUncrossedLines(int[] nums1, int[] nums2) {
        int m = nums1.length;
        int n = nums2.length;
        int[][] dp = new int[m + 1][n + 1];
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(nums1[i - 1] == nums2[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }else{
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
        
    }
}

    