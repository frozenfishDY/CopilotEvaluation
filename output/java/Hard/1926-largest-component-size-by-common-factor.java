/**https://leetcode.com/problems/largest-component-size-by-common-factor/ */
//You are given an integer array of unique positive integers nums. Consider the following graph:
//There are nums.length nodes, labeled nums[0] to nums[nums.length - 1],
//There is an undirected edge between nums[i] and nums[j] if nums[i] and nums[j] share a common factor greater than 1.
//Return the size of the largest connected component in the graph.


class LargestComponentSizeByCommonFactor {
    public int largestComponentSize(int[] nums) {
        int n = nums.length;
        int[] parent = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (gcd(nums[i], nums[j]) > 1) {
                    union(parent, i, j);
                }
            }
        }
        int[] count = new int[n];
        int res = 0;
        for (int i = 0; i < n; i++) {
            int p = find(parent, i);
            count[p]++;
            res = Math.max(res, count[p]);
        }
        return res;
        
    }
}
     
    