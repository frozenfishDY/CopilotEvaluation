/**https://leetcode.com/problems/non-decreasing-subsequences/ */
//Given an integer array nums, return all the different possible non-decreasing subsequences of the given array with at least two elements. You may return the answer in any order.
// 
//Example 1:
//Input: nums = [4,6,7,7]
//Output: [[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]
//Example 2:
//Input: nums = [4,4,3,2,1]
//Output: [[4,4]]
// 
//Constraints:
//	1 <= nums.length <= 15
//	-100 <= nums[i] <= 100
class Solution {
    public List<List<Integer>> findSubsequences(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        dfs(nums, 0, new ArrayList<>(), result);
        return result;
    }
    private void dfs(int[] nums, int index, List<Integer> list, List<List<Integer>> result) {
        if (list.size() >= 2) {
            result.add(new ArrayList<>(list));
        }
        if (index >= nums.length) {
            return;
        }
        Set<Integer> set = new HashSet<>();
        for (int i = index; i < nums.length; i++) {
            if (set.contains(nums[i])) {
                continue;
            }
            if (list.size() == 0 || nums[i] >= list.get(list.size() - 1)) {
                set.add(nums[i]);
                list.add(nums[i]);
                dfs(nums, i + 1, list, result);
                list.remove(list.size() - 1);
            }
        }
    }
}