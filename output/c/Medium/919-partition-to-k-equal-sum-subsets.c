/**https://leetcode.com/problems/partition-to-k-equal-sum-subsets/ */
//Given an integer array nums and an integer k, return true if it is possible to divide this array into k non-empty subsets whose sums are all equal.
// 
//Example 1:
//Input: nums = [4,3,2,3,5,2,1], k = 4
//Output: true
//Explanation: It is possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.
//Example 2:
//Input: nums = [1,2,3,4], k = 3
//Output: false
// 
//Constraints:
//	1 <= k <= nums.length <= 16
//	1 <= nums[i] <= 104
//	The frequency of each element is in the range [1, 4].
bool canPartitionKSubsets(int* nums, int numsSize, int k){ 
int sum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
    }
    if (sum % k != 0) {
        return false;
    }
    int target = sum / k;
    int used[16] = {0};
    int current = 0;
    for (int i = 0; i < numsSize; i++) {
        if (used[i] == 0) {
            current += nums[i];
            if (current == target) {
                current = 0;
            } else if (current > target) {
                return false;
            } else {
                for (int j = i + 1; j < numsSize; j++) {
                    if (used[j] == 0) {
                        int temp = current + nums[j];
                        if (temp <= target) {
                            current = temp;
                            used[j] = 1;
                            if (current == target) {
                                current = 0;
                                break;
                            }
                        }
                    }
                }
                if (current > 0) {
                    return false;
                }
            }
        }
    }
    return true;
}