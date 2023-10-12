/**https://leetcode.com/problems/number-of-pairs-satisfying-inequality/ */
//You are given two 0-indexed integer arrays nums1 and nums2, each of size n, and an integer diff. Find the number of pairs (i, j) such that:
//	0 <= i < j <= n - 1 and
//	nums1[i] - nums1[j] <= nums2[i] - nums2[j] + diff.
//Return the number of pairs that satisfy the conditions.
// 
//Example 1:
//Input: nums1 = [3,2,5], nums2 = [2,2,1], diff = 1
//Output: 3
//Explanation:
//There are 3 pairs that satisfy the conditions:
//1. i = 0, j = 1: 3 - 2 <= 2 - 2 + 1. Since i < j and 1 <= 1, this pair satisfies the conditions.
//2. i = 0, j = 2: 3 - 5 <= 2 - 1 + 1. Since i < j and -2 <= 2, this pair satisfies the conditions.
//3. i = 1, j = 2: 2 - 5 <= 2 - 1 + 1. Since i < j and -3 <= 2, this pair satisfies the conditions.
//Therefore, we return 3.
//Example 2:
//Input: nums1 = [3,-1], nums2 = [-2,2], diff = -1
//Output: 0
//Explanation:
//Since there does not exist any pair that satisfies the conditions, we return 0.
// 
//Constraints:
//	n == nums1.length == nums2.length
//	2 <= n <= 105
//	-104 <= nums1[i], nums2[i] <= 104
//	-104 <= diff <= 104
class Solution {
    public long numberOfPairs(int[] nums1, int[] nums2, int diff) {
        int n = nums1.length;
        int[][] pairs = new int[n][2];
        for (int i = 0; i < n; i++) {
            pairs[i] = new int[]{nums1[i] - nums2[i], nums1[i]};
        }
        Arrays.sort(pairs, (a, b) -> a[0] - b[0]);
        long res = 0;
        for (int i = 0; i < n; i++) {
            int left = i + 1, right = n;
            while (left < right) {
                int mid = left + right >> 1;
                if (pairs[mid][0] < pairs[i][0] + diff) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
            res += n - right;
        }
        return res;
    }
}