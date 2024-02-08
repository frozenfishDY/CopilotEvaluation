/**https://leetcode.com/problems/handling-sum-queries-after-update/ */
//You are given two 0-indexed arrays nums1 and nums2 and a 2D array queries of queries. There are three types of queries:
//For a query of type 1, queries[i] = [1, l, r]. Flip the values from 0 to 1 and from 1 to 0 in nums1 from index l to index r. Both l and r are 0-indexed.
//For a query of type 2, queries[i] = [2, p, 0]. For every index 0 <= i < n, set nums2[i] = nums2[i] + nums1[i] * p.
//For a query of type 3, queries[i] = [3, 0, 0]. Find the sum of the elements in nums2.
//Return an array containing all the answers to the third type queries.


class HandlingSumQueriesAfterUpdate {
    public long[] handleQuery(int[] nums1, int[] nums2, int[][] queries) {
        int n = nums1.length;
        int m = queries.length;
        long[] ans = new long[m];
        int[] nums1Copy = new int[n];
        for (int i = 0; i < n; i++) {
            nums1Copy[i] = nums1[i];
        }
        for (int i = 0; i < m; i++) {
            int type = queries[i][0];
            if (type == 1) {
                int l = queries[i][1];
                int r = queries[i][2];
                for (int j = l; j <= r; j++) {
                    nums1[j] = 1 - nums1[j];
                }
            } else if (type == 2) {
                int p = queries[i][1];
                for (int j = 0; j < n; j++) {
                    nums2[j] += nums1[j] * p;
                }
            } else {
                long sum = 0;
                for (int j = 0; j < n; j++) {
                    sum += nums2[j];
                }
                ans[i] = sum;
            }
        }
        return ans;
        
    }
}
     
    