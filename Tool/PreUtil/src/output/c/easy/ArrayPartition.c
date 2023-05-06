/**https://leetcode.com/problems/array-partition/ */
//Given an integer array nums of 2n integers, group these integers into n pairs (a1, b1), (a2, b2), ..., (an, bn) such that the sum of min(ai, bi) for all i is maximized. Return the maximized sum.


int arrayPairSum(int* nums, int numsSize){
    int result = 0;
    int i = 0;
    int j = 0;
    int temp = 0;
    for(i = 0; i < numsSize - 1; i++){
        for(j = 0; j < numsSize - i - 1; j++){
            if(nums[j] > nums[j + 1]){
                temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }
    for(i = 0; i < numsSize; i += 2){
        result += nums[i];
    }
    return result;

}

    