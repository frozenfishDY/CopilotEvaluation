/**https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/ */
//Given an integer array nums and two integers left and right, return the number of contiguous non-empty subarrays such that the value of the maximum array element in that subarray is in the range [left, right].
//The test cases are generated so that the answer will fit in a 32-bit integer.


int numSubarrayBoundedMax(int* nums, int numsSize, int left, int right){
    int* result = (int*)malloc(sizeof(int) * numsSize);
    int count = 0;
    for(int i = 0; i < numsSize; i++){
        if(nums[i] >= left && nums[i] <= right){
            result[i] = 1;
            count++;
        }else{
            result[i] = 0;
        }
    }
    for(int i = 1; i < numsSize; i++){
        if(result[i] == 1){
            result[i] = result[i - 1] + 1;
            count += result[i];
        }
    }
    return count;

}

    