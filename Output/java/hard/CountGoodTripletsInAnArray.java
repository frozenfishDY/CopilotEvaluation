/**https://leetcode.com/problems/count-good-triplets-in-an-array/ */
//You are given two 0-indexed arrays nums1 and nums2 of length n, both of which are permutations of [0, 1, ..., n - 1].
//A good triplet is a set of 3 distinct values which are present in increasing order by position both in nums1 and nums2. In other words, if we consider pos1v as the index of the value v in nums1 and pos2v as the index of the value v in nums2, then a good triplet will be a set (x, y, z) where 0 <= x, y, z <= n - 1, such that pos1x < pos1y < pos1z and pos2x < pos2y < pos2z.
//Return the total number of good triplets.


class CountGoodTripletsInAnArray {
    public long goodTriplets(int[] nums1, int[] nums2) {
        int n = nums1.length;
        long res = 0;
        for (int i = 0; i < n; i++) {
            int[] count1 = new int[n];
            int[] count2 = new int[n];
            for (int j = i + 1; j < n; j++) {
                if (nums1[j] > nums1[i]) {
                    count1[nums1[j]]++;
                }
                if (nums2[j] > nums2[i]) {
                    count2[nums2[j]]++;
                }
            }
            for (int j = i + 1; j < n; j++) {
                if (nums1[j] > nums1[i]) {
                    for (int k = nums1[j] + 1; k < n; k++) {
                        res += count1[k] * count2[k];
                    }
                }
            }
        }
        return res;
        
    }
}
     
    