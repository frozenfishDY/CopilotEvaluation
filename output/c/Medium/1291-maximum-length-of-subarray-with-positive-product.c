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
int getMaxLen(int* nums, int numsSize){
int i;
    int max = 0;
    int count = 0;
    int negative = 0;
    int first_negative = -1;
    int first_zero = -1;
    for (i = 0; i < numsSize; i++)
    {
        if (nums[i] == 0)
        {
            count = 0;
            negative = 0;
            first_negative = -1;
            first_zero = i;
        }
        else
        {
            count++;
            if (nums[i] < 0)
            {
                negative++;
                if (first_negative == -1)
                {
                    first_negative = i;
                }
            }
            if (negative % 2 == 0)
            {
                if (count > max)
                {
                    max = count;
                }
            }
            else
            {
                if (count - 1 > max)
                {
                    max = count - 1;
                }
            }
        }
    }
    return max;
}