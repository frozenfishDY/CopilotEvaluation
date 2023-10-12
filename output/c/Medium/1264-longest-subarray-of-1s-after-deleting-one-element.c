/**https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/ */
//Given a binary array nums, you should delete one element from it.
//Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.
// 
//Example 1:
//Input: nums = [1,1,0,1]
//Output: 3
//Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.
//Example 2:
//Input: nums = [0,1,1,1,0,1,1,0,1]
//Output: 5
//Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].
//Example 3:
//Input: nums = [1,1,1]
//Output: 2
//Explanation: You must delete one element.
// 
//Constraints:
//	1 <= nums.length <= 105
//	nums[i] is either 0 or 1.
int longestSubarray(int* nums, int numsSize){
int max = 0;
    int count = 0;
    int count1 = 0;
    int count0 = 0;
    int start = 0;
    int end = 0;
    while (end < numsSize) {
        if (nums[end] == 1) {
            count1++;
        }
        if (nums[end] == 0) {
            count0++;
        }
        end++;
        count++;
        if (count0 > 1) {
            while (start < end) {
                if (nums[start] == 1) {
                    count1--;
                }
                if (nums[start] == 0) {
                    count0--;
                }
                start++;
                count--;
                if (count0 <= 1) {
                    break;
                }
            }
        }
        if (count > max) {
            max = count;
        }
    }
    return max - 1;
}