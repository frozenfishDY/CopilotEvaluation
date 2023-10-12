/**https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product/ */
//Given an array of integers nums, find the maximum length of a subarray where the product of all its elements is positive.
//A subarray of an array is a consecutive sequence of zero or more values taken out of that array.
//Return the maximum length of a subarray with positive product.
// 
//Example 1:
//Input: nums = [1,-2,-3,4]
//Output: 4
//Explanation: The array nums already has a positive product of 24.
//Example 2:
//Input: nums = [0,1,-2,-3,-4]
//Output: 3
//Explanation: The longest subarray with positive product is [1,-2,-3] which has a product of 6.
//Notice that we cannot include 0 in the subarray since that'll make the product 0 which is not positive.
//Example 3:
//Input: nums = [-1,-2,-3,0,1]
//Output: 2
//Explanation: The longest subarray with positive product is [-1,-2] or [-2,-3].
// 
//Constraints:
//	1 <= nums.length <= 105
//	-109 <= nums[i] <= 109
class Solution {
    public int getMaxLen(int[] nums) {
        int res = 0;
        int start = 0;
        int firstNeg = 0;
        int negCount = 0;
        for(int i = 0; i < nums.length; i++){
            if(nums[i] == 0){
                start = i + 1;
                firstNeg = 0;
                negCount = 0;
            }else{
                if(nums[i] < 0){
                    if(firstNeg == 0){
                        firstNeg = i + 1;
                    }
                    negCount++;
                }
                if(negCount % 2 == 0){
                    res = Math.max(res, i - start + 1);
                }else{
                    res = Math.max(res, i - firstNeg + 1);
                }
            }
        }
        return res;
    }
}