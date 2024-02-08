/**https://leetcode.com/problems/max-value-of-equation/ */
//You are given an array points containing the coordinates of points on a 2D plane, sorted by the x-values, where points[i] = [xi, yi] such that xi < xj for all 1 <= i < j <= points.length. You are also given an integer k.
//Return the maximum value of the equation yi + yj + |xi - xj| where |xi - xj| <= k and 1 <= i < j <= points.length.
//It is guaranteed that there exists at least one pair of points that satisfy the constraint |xi - xj| <= k.


class MaxValueOfEquation {
    public int findMaxValueOfEquation(int[][] points, int k) {
        int n = points.length;
        int ans = Integer.MIN_VALUE;
        Deque<int[]> dq = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            int[] p = points[i];
            while (!dq.isEmpty() && p[0] - dq.peekFirst()[0] > k) {
                dq.pollFirst();
            }
            if (!dq.isEmpty()) {
                ans = Math.max(ans, p[0] + p[1] + dq.peekFirst()[1]);
            }
            while (!dq.isEmpty() && p[1] - p[0] >= dq.peekLast()[1] - dq.peekLast()[0]) {
                dq.pollLast();
            }
            dq.offerLast(new int[]{p[0], p[1] - p[0]});
        }
        return ans;
        
    }
}
     
    