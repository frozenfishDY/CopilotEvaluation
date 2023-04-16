/**https://leetcode.com/problems/make-the-xor-of-all-segments-equal-to-zero/ */
//You are given an array nums and an integer k . The XOR of a segment [left, right] where left <= right is the XOR of all the elements with indices between left and right, inclusive: nums[left] XOR nums[left+1] XOR ... XOR nums[right].
//Return the minimum number of elements to change in the array such that the XOR of all segments of size k is equal to zero.


class MakeTheXorOfAllSegmentsEqualToZero {
    public int minChanges(int[] nums, int k) {
        int n = nums.length;
        int[] f = new int[1 << 10];
        Arrays.fill(f, n);
        f[0] = 0;
        for (int i = 0; i < k; i++) {
            int cnt = 0;
            int[] g = new int[1 << 10];
            Arrays.fill(g, n);
            int[] cnts = new int[1 << 10];
            for (int j = i; j < n; j += k) {
                cnts[nums[j]]++;
                cnt++;
            }
            for (int mask = 0; mask < 1 << 10; mask++) {
                g[mask] = Math.min(g[mask], f[mask] + cnt);
                for (int j = 0; j < 1 << 10; j++) {
                    g[j ^ mask] = Math.min(g[j ^ mask], f[mask] + cnt - cnts[j]);
                }
            }
            f = g;
        }
        return f[0];
        
    }
}
     
    