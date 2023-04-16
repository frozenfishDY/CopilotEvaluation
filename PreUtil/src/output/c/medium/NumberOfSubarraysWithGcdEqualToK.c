/**https://leetcode.com/problems/number-of-subarrays-with-gcd-equal-to-k/ */
//Given an integer array nums and an integer k, return the number of subarrays of nums where the greatest common divisor of the subarray's elements is k.
//A subarray is a contiguous non-empty sequence of elements within an array.
//The greatest common divisor of an array is the largest integer that evenly divides all the array elements.


int subarrayGCD(int* nums, int numsSize, int k){
    int i, j, l, m, n, count = 0;
    int arr[100000] = {0};
    for(i = 0; i < numsSize; i++){
        for(j = 0; j < 100000; j++){
            if(nums[i] + j * k < 100000){
                arr[nums[i] + j * k] = 1;
            }
        }
    }
    for(i = 0; i < 100000; i++){
        if(arr[i] == 1){
            count++;
        }
    }
    return count;


}

    