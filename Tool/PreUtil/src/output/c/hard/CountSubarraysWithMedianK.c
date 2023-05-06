/**https://leetcode.com/problems/count-subarrays-with-median-k/ */
//You are given an array nums of size n consisting of distinct integers from 1 to n and a positive integer k.
//Return the number of non-empty subarrays in nums that have a median equal to k.
//Note:
//The median of an array is the middle element after sorting the array in ascending order. If the array is of even length, the median is the left middle element.
//For example, the median of [2,3,1,4] is 2, and the median of [8,4,3,5,1] is 4.
//A subarray is a contiguous part of an array.


int countSubarrays(int* nums, int numsSize, int k){
    int i,j,k;
    int* arr = (int*)malloc(sizeof(int)*numsSize);
    for(i=0;i<numsSize;i++){
        arr[i] = 0;
    }
    arr[0] = 1;
    for(i=1;i<numsSize;i++){
        arr[i] = arr[i-1] + 1;
        if(i%2==0){
            arr[i] = (arr[i] < arr[i/2] + 1) ? arr[i] : arr[i/2] + 1;
        }
        if(i%3==0){
            arr[i] = (arr[i] < arr[i/3] + 1) ? arr[i] : arr[i/3] + 1;
        }
    }
    return arr[numsSize-1];

}

    