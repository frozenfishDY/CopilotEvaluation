/**https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/ */
//You have k lists of sorted integers in non-decreasing order. Find the smallest range that includes at least one number from each of the k lists.
//We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.
// 
//Example 1:
//Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
//Output: [20,24]
//Explanation: 
//List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
//List 2: [0, 9, 12, 20], 20 is in range [20,24].
//List 3: [5, 18, 22, 30], 22 is in range [20,24].
//Example 2:
//Input: nums = [[1,2,3],[1,2,3],[1,2,3]]
//Output: [1,1]
// 
//Constraints:
//	nums.length == k
//	1 <= k <= 3500
//	1 <= nums[i].length <= 50
//	-105 <= nums[i][j] <= 105
//	nums[i] is sorted in non-decreasing order.
class Solution {
    public int[] smallestRange(List<List<Integer>> nums) {
        int n = nums.size(), max = Integer.MIN_VALUE, start = 0, end = Integer.MAX_VALUE;
        int[] next = new int[n], res = new int[2];
        boolean flag = true;
        PriorityQueue<Integer> pq = new PriorityQueue<Integer>((i, j) -> nums.get(i).get(next[i]) - nums.get(j).get(next[j]));
        for (int i = 0; i < n; i++) {
            pq.offer(i);
            max = Math.max(max, nums.get(i).get(0));
        }
        for (int i = 0; i < n && flag; i++) {
            for (int j = 0; j < nums.get(i).size() && flag; j++) {
                int min_i = pq.poll();
                if (end - start > max - nums.get(min_i).get(next[min_i])) {
                    start = nums.get(min_i).get(next[min_i]);
                    end = max;
                }
                next[min_i]++;
                if (next[min_i] == nums.get(min_i).size()) {
                    flag = false;
                    break;
                }
                pq.offer(min_i);
                max = Math.max(max, nums.get(min_i).get(next[min_i]));
            }
        }
        res[0] = start;
        res[1] = end;
        return res;
    }
}