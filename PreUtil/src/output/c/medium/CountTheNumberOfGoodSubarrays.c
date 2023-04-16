/**https://leetcode.com/problems/count-the-number-of-good-subarrays/ */
//Given an integer array nums and an integer k, return the number of good subarrays of nums.
//A subarray arr is good if it there are at least k pairs of indices (i, j) such that i < j and arr[i] == arr[j].
//A subarray is a contiguous non-empty sequence of elements within an array.


long long countGood(int* nums, int numsSize, int k){
    int* result = (int*)malloc(sizeof(int) * (numsSize + 1));
    result[0] = 0;
    for(int i = 1; i <= numsSize; i++){
        result[i] = result[i - 1] + (nums[i - 1] % 2);
    }
    long long count = 0;
    for(int i = 0; i < numsSize; i++){
        for(int j = i + 1; j <= numsSize; j++){
            if(result[j] - result[i] >= k){
                count++;
            }
        }
    }
    return count;

}

    