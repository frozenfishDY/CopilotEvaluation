/**https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/ */
//Nearly everyone has used the Multiplication Table. The multiplication table of size m x n is an integer matrix mat where mat[i][j] == i * j (1-indexed).
//Given three integers m, n, and k, return the kth smallest element in the m x n multiplication table.


class KthSmallestNumberInMultiplicationTable {
    public int findKthNumber(int m, int n, int k) {
        int left = 1;
        int right = m * n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            int count = 0;
            for (int i = 1; i <= m; i++) {
                count += Math.min(mid / i, n);
            }
            if (count < k) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
        
    }
}
     
    