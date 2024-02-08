/**https://leetcode.com/problems/tuple-with-same-product/ */
//Given an array nums of distinct positive integers, return the number of tuples (a, b, c, d) such that a * b = c * d where a, b, c, and d are elements of nums, and a != b != c != d.


int tupleSameProduct(int* nums, int numsSize){
    int count = 0;
    for(int i = 0; i < numsSize; i++){
        for(int j = i + 1; j < numsSize; j++){
            for(int k = j + 1; k < numsSize; k++){
                for(int l = k + 1; l < numsSize; l++){
                    if(nums[i] * nums[j] == nums[k] * nums[l]){
                        count++;
                    }
                }
            }
        }
    }
    return count * 8;

}

    