/**https://leetcode.com/problems/find-the-kth-smallest-sum-of-a-matrix-with-sorted-rows/ */
//You are given an m x n matrix mat that has its rows sorted in non-decreasing order and an integer k.
//You are allowed to choose exactly one element from each row to form an array.
//Return the kth smallest array sum among all possible arrays.


class FindTheKthSmallestSumOfAMatrixWithSortedRows {
    public int kthSmallest(int[][] mat, int k) {
        int m = mat.length;
        int n = mat[0].length;
        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> b - a);
        pq.offer(0);
        for (int i = 0; i < m; i++) {
            PriorityQueue<Integer> next = new PriorityQueue<>((a, b) -> b - a);
            for (int j = 0; j < n; j++) {
                for (int sum : pq) {
                    next.offer(sum + mat[i][j]);
                    if (next.size() > k) {
                        next.poll();
                    }
                }
            }
            pq = next;
        }
        return pq.poll();
        
    }
}
     
    