/**https://leetcode.com/problems/find-xor-beauty-of-array/ */
//You are given a 0-indexed integer array nums.
//The effective value of three indices i, j, and k is defined as ((nums[i] | nums[j]) & nums[k]).
//The xor-beauty of the array is the XORing of the effective values of all the possible triplets of indices (i, j, k) where 0 <= i, j, k < n.
//Return the xor-beauty of nums.
//Note that:
//val1 | val2 is bitwise OR of val1 and val2.
//val1 & val2 is bitwise AND of val1 and val2.


int xorBeauty(int* nums, int numsSize){
    int result = 0;
    for(int i = 0; i < numsSize; i++){
        for(int j = 0; j < numsSize; j++){
            for(int k = 0; k < numsSize; k++){
                result ^= (nums[i] | nums[j]) & nums[k];
            }
        }
    }
    return result;


}

    