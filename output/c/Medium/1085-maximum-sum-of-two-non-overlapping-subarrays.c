/**https://leetcode.com/problems/maximum-sum-of-two-non-overlapping-subarrays/ */
//Given an integer array nums and two integers firstLen and secondLen, return the maximum sum of elements in two non-overlapping subarrays with lengths firstLen and secondLen.
//The array with length firstLen could occur before or after the array with length secondLen, but they have to be non-overlapping.
//A subarray is a contiguous part of an array.


int maxSumTwoNoOverlap(int* nums, int numsSize, int firstLen, int secondLen){
    int* first = (int*)malloc(sizeof(int) * numsSize);
    int* second = (int*)malloc(sizeof(int) * numsSize);
    int sum = 0;
    for(int i = 0; i < firstLen; i++){
        sum += nums[i];
    }
    first[firstLen - 1] = sum;
    for(int i = firstLen; i < numsSize; i++){
        sum += nums[i] - nums[i - firstLen];
        first[i] = sum;
    }
    sum = 0;
    for(int i = 0; i < secondLen; i++){
        sum += nums[i];
    }
    second[secondLen - 1] = sum;
    for(int i = secondLen; i < numsSize; i++){
        sum += nums[i] - nums[i - secondLen];
        second[i] = sum;
    }
    int max = 0;
    for(int i = firstLen - 1; i < numsSize; i++){
        for(int j = secondLen - 1; j < numsSize; j++){
            if(i - firstLen + 1 > j || j - secondLen + 1 > i){
                int temp = first[i] + second[j];
                if(temp > max){
                    max = temp;
                }
            }
        }
    }
    return max;


}

    