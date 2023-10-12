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
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParityII(int* nums, int numsSize, int* returnSize){
int *returnNums = malloc(sizeof(int)*numsSize);
    int i,j;
    for(i=0,j=0;i<numsSize;i++){
        if(nums[i]%2==0){
            returnNums[j]=nums[i];
            j+=2;
        }
    }
    for(i=0,j=1;i<numsSize;i++){
        if(nums[i]%2==1){
            returnNums[j]=nums[i];
            j+=2;
        }
    }
    *returnSize=numsSize;
    return returnNums;
}