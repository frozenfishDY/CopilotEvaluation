/**https://leetcode.com/problems/find-all-lonely-numbers-in-the-array/ */
//You are given an integer array nums. A number x is lonely when it appears only once, and no adjacent numbers (i.e. x + 1 and x - 1) appear in the array.
//Return all lonely numbers in nums. You may return the answer in any order.
// 
//Example 1:
//Input: nums = [10,6,5,8]
//Output: [10,8]
//Explanation: 
//- 10 is a lonely number since it appears exactly once and 9 and 11 does not appear in nums.
//- 8 is a lonely number since it appears exactly once and 7 and 9 does not appear in nums.
//- 5 is not a lonely number since 6 appears in nums and vice versa.
//Hence, the lonely numbers in nums are [10, 8].
//Note that [8, 10] may also be returned.
//Example 2:
//Input: nums = [1,3,5,3]
//Output: [1,5]
//Explanation: 
//- 1 is a lonely number since it appears exactly once and 0 and 2 does not appear in nums.
//- 5 is a lonely number since it appears exactly once and 4 and 6 does not appear in nums.
//- 3 is not a lonely number since it appears twice.
//Hence, the lonely numbers in nums are [1, 5].
//Note that [5, 1] may also be returned.
// 
//Constraints:
//	1 <= nums.length <= 105
//	0 <= nums[i] <= 106
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findLonely(int* nums, int numsSize, int* returnSize){
int* ret = malloc(sizeof(int)*numsSize);
    int i;
    int j;
    int k;
    int count;
    int left;
    int right;
    for(i=0;i<numsSize;i++){
        count=0;
        for(j=0;j<numsSize;j++){
            if(nums[i]==nums[j]){
                count++;
            }
        }
        if(count==1){
            ret[i]=nums[i];
        }else{
            ret[i]=0;
        }
    }
    *returnSize=numsSize;
    return ret;
}