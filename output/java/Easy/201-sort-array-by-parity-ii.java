/**https://leetcode.com/problems/sort-array-by-parity-ii/ */
//Given an array of integers nums, half of the integers in nums are odd, and the other half are even.
//Sort the array so that whenever nums[i] is odd, i is odd, and whenever nums[i] is even, i is even.
//Return any answer array that satisfies this condition.
// 
//Example 1:
//Input: nums = [4,2,5,7]
//Output: [4,5,2,7]
//Explanation: [4,7,2,5], [2,5,4,7], [2,7,4,5] would also have been accepted.
//Example 2:
//Input: nums = [2,3]
//Output: [2,3]
// 
//Constraints:
//	2 <= nums.length <= 2 * 104
//	nums.length is even.
//	Half of the integers in nums are even.
//	0 <= nums[i] <= 1000
// 
//Follow Up: Could you solve it in-place?
class Solution {
    public int[] sortArrayByParityII(int[] nums) {
        int len = nums.length;
        int[] res = new int[len];
        int even = 0;
        int odd = 1;
        for(int i = 0; i < len; i++){
            if(nums[i] % 2 == 0){
                res[even] = nums[i];
                even += 2;
            }else{
                res[odd] = nums[i];
                odd += 2;
            }
        }
        return res;
    }
}