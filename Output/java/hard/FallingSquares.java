/**https://leetcode.com/problems/falling-squares/ */
//There are several squares being dropped onto the X-axis of a 2D plane.
//You are given a 2D integer array positions where positions[i] = [lefti, sideLengthi] represents the ith square with a side length of sideLengthi that is dropped with its left edge aligned with X-coordinate lefti.
//Each square is dropped one at a time from a height above any landed squares. It then falls downward (negative Y direction) until it either lands on the top side of another square or on the X-axis. A square brushing the left/right side of another square does not count as landing on it. Once it lands, it freezes in place and cannot be moved.
//After each square is dropped, you must record the height of the current tallest stack of squares.
//Return an integer array ans where ans[i] represents the height described above after dropping the ith square.


class FallingSquares {
    public List<Integer> fallingSquares(int[][] positions) {
        List<Integer> ans = new ArrayList<>();
        int n = positions.length;
        int[] dp = new int[n];
        int max = 0;
        for (int i = 0; i < n; i++) {
            int left = positions[i][0];
            int right = left + positions[i][1];
            int height = positions[i][1];
            dp[i] = height;
            for (int j = 0; j < i; j++) {
                int left2 = positions[j][0];
                int right2 = left2 + positions[j][1];
                if (left2 < right && left < right2) {
                    dp[i] = Math.max(dp[i], dp[j] + height);
                }
            }
            max = Math.max(max, dp[i]);
            ans.add(max);
        }
        return ans;
        
    }
}
     
    