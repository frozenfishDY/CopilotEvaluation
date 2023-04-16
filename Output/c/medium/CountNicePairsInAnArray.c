/**https://leetcode.com/problems/count-nice-pairs-in-an-array/ */
//You are given an array nums that consists of non-negative integers. Let us define rev(x) as the reverse of the non-negative integer x. For example, rev(123) = 321, and rev(120) = 21. A pair of indices (i, j) is nice if it satisfies all of the following conditions:
//0 <= i < j < nums.length
//nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])
//Return the number of nice pairs of indices. Since that number can be too large, return it modulo 109 + 7.


int countNicePairs(int* nums, int numsSize){
    int i, j;
    int count = 0;
    int mod = 1000000007;
    for(i = 0; i < numsSize; i++){
        for(j = i + 1; j < numsSize; j++){
            if(nums[i] + reverse(nums[j]) == nums[j] + reverse(nums[i])){
                count++;
            }
        }
    }
    return count % mod;

}

    