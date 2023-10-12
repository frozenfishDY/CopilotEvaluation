/**https://leetcode.com/problems/all-divisions-with-the-highest-score-of-a-binary-array/ */
//You are given a 0-indexed binary array nums of length n. nums can be divided at index i (where 0 <= i <= n) into two arrays (possibly empty) numsleft and numsright:
//	numsleft has all the elements of nums between index 0 and i - 1 (inclusive), while numsright has all the elements of nums between index i and n - 1 (inclusive).
//	If i == 0, numsleft is empty, while numsright has all the elements of nums.
//	If i == n, numsleft has all the elements of nums, while numsright is empty.
//The division score of an index i is the sum of the number of 0's in numsleft and the number of 1's in numsright.
//Return all distinct indices that have the highest possible division score. You may return the answer in any order.
// 
//Example 1:
//Input: nums = [0,0,1,0]
//Output: [2,4]
//Explanation: Division at index
//- 0: numsleft is []. numsright is [0,0,1,0]. The score is 0 + 1 = 1.
//- 1: numsleft is [0]. numsright is [0,1,0]. The score is 1 + 1 = 2.
//- 2: numsleft is [0,0]. numsright is [1,0]. The score is 2 + 1 = 3.
//- 3: numsleft is [0,0,1]. numsright is [0]. The score is 2 + 0 = 2.
//- 4: numsleft is [0,0,1,0]. numsright is []. The score is 3 + 0 = 3.
//Indices 2 and 4 both have the highest possible division score 3.
//Note the answer [4,2] would also be accepted.
//Example 2:
//Input: nums = [0,0,0]
//Output: [3]
//Explanation: Division at index
//- 0: numsleft is []. numsright is [0,0,0]. The score is 0 + 0 = 0.
//- 1: numsleft is [0]. numsright is [0,0]. The score is 1 + 0 = 1.
//- 2: numsleft is [0,0]. numsright is [0]. The score is 2 + 0 = 2.
//- 3: numsleft is [0,0,0]. numsright is []. The score is 3 + 0 = 3.
//Only index 3 has the highest possible division score 3.
//Example 3:
//Input: nums = [1,1]
//Output: [0]
//Explanation: Division at index
//- 0: numsleft is []. numsright is [1,1]. The score is 0 + 2 = 2.
//- 1: numsleft is [1]. numsright is [1]. The score is 0 + 1 = 1.
//- 2: numsleft is [1,1]. numsright is []. The score is 0 + 0 = 0.
//Only index 0 has the highest possible division score 2.
// 
//Constraints:
//	n == nums.length
//	1 <= n <= 105
//	nums[i] is either 0 or 1.
class Solution {
    public List<Integer> maxScoreIndices(int[] nums) {
        int n = nums.length;
        int[] left = new int[n];
        int[] right = new int[n];
        int[] pre = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            pre[i] = pre[i - 1];
            if (nums[i - 1] > nums[i]) {
                pre[i]++;
            }
        }
        for (int i = 0; i < n; i++) {
            int l = 0, r = i - 1;
            while (l < r) {
                int mid = l + r >> 1;
                if (nums[mid] < nums[i]) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
            if (nums[l] < nums[i]) {
                left[i] = i - l;
            } else {
                left[i] = i - l - 1;
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            int l = i + 1, r = n - 1;
            while (l < r) {
                int mid = l + r + 1 >> 1;
                if (nums[mid] < nums[i]) {
                    r = mid - 1;
                } else {
                    l = mid;
                }
            }
            if (nums[l] < nums[i]) {
                right[i] = l - i;
            } else {
                right[i] = l - i - 1;
            }
        }
        int max = 0;
        for (int i = 0; i < n; i++) {
            max = Math.max(max, left[i] + right[i]);
        }
        List<Integer> res = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if (left[i] + right[i] == max) {
                res.add(i);
            }
        }
        return res;
    }
}