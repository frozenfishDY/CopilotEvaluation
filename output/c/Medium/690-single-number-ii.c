/**https://leetcode.com/problems/single-number-ii/ */
//Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.
//You must implement a solution with a linear runtime complexity and use only constant extra space.


int singleNumber(int* nums, int numsSize){
    int result = 0;
    for(int i = 0; i < 32; i++){
        int count = 0;
        for(int j = 0; j < numsSize; j++){
            if(nums[j] & (1 << i)){
                count++;
            }
        }
        if(count % 3 != 0){
            result |= (1 << i);
        }
    }
    return result;

}

    