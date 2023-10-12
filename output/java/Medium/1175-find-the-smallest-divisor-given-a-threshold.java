/**https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/ */
//Given an array of integers nums and an integer threshold, we will choose a positive integer divisor, divide all the array by it, and sum the division's result. Find the smallest divisor such that the result mentioned above is less than or equal to threshold.
//Each result of the division is rounded to the nearest integer greater than or equal to that element. (For example: 7/3 = 3 and 10/2 = 5).
//The test cases are generated so that there will be an answer.
// 
//Example 1:
//Input: nums = [1,2,5,9], threshold = 6
//Output: 5
//Explanation: We can get a sum to 17 (1+2+5+9) if the divisor is 1. 
//If the divisor is 4 we can get a sum of 7 (1+1+2+3) and if the divisor is 5 the sum will be 5 (1+1+1+2). 
//Example 2:
//Input: nums = [44,22,33,11,1], threshold = 5
//Output: 44
// 
//Constraints:
//	1 <= nums.length <= 5 * 104
//	1 <= nums[i] <= 106
//	nums.length <= threshold <= 106
class Solution {
    public int smallestDivisor(int[] nums, int threshold) {
        // 1. create a variable to store the result
		// 2. create two variables to store the left and right boundary
		// 3. while the left boundary is smaller than the right boundary
		// 3.1 calculate the mid point
		// 3.2 calculate the sum of the division of each element in the array by the mid point
		// 3.3 if the sum is greater than the threshold
		// 3.3.1 move the left boundary to the right by 1
		// 3.4 else
		// 3.4.1 move the right boundary to the left by 1
		// 4. return the left boundary
        int result = 0;
        int left = 1;
        int right = 1000000;
        while(left < right) {
            int mid = (left + right) / 2;
            int sum = 0;
            for(int i = 0; i < nums.length; i++) {
                sum += (nums[i] - 1) / mid + 1;
            }
            if(sum > threshold) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        return left;
    }
}