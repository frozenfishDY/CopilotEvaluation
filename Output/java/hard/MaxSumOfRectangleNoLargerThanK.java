/**https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/ */
//Given an m x n matrix matrix and an integer k, return the max sum of a rectangle in the matrix such that its sum is no larger than k.
//It is guaranteed that there will be a rectangle with a sum no larger than k.


class MaxSumOfRectangleNoLargerThanK {
    public int maxSumSubmatrix(int[][] matrix, int k) {
        int m = matrix.length;
        int n = matrix[0].length;
        int ans = Integer.MIN_VALUE;
        for (int i = 0; i < m; i++) {
            int[] rowSum = new int[n];
            for (int j = i; j < m; j++) {
                for (int c = 0; c < n; c++) {
                    rowSum[c] += matrix[j][c];
                }
                TreeSet<Integer> set = new TreeSet<>();
                set.add(0);
                int sum = 0;
                for (int c = 0; c < n; c++) {
                    sum += rowSum[c];
                    Integer ceiling = set.ceiling(sum - k);
                    if (ceiling != null) {
                        ans = Math.max(ans, sum - ceiling);
                    }
                    set.add(sum);
                }
            }
        }
        return ans;
        
    }
}
     
    