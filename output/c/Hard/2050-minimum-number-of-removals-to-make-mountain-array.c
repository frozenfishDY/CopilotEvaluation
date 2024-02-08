/**https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/ */
//You may recall that an array arr is a mountain array if and only if:
//arr.length >= 3
//There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
//arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
//arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
//Given an integer array nums, return the minimum number of elements to remove to make nums a mountain array.


int minimumMountainRemovals(int* nums, int numsSize){
    int i,j,k;
    int* arr = (int*)malloc(sizeof(int)*numsSize);
    for(i=0;i<numsSize;i++){
        arr[i] = 1;
    }
    for(i=1;i<numsSize;i++){
        for(j=0;j<i;j++){
            if(nums[j] < nums[i]){
                arr[i] = (arr[i] < arr[j] + 1) ? arr[i] : arr[j] + 1;
            }
        }
    }
    int max = 0;
    for(i=0;i<numsSize;i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    int* arr2 = (int*)malloc(sizeof(int)*numsSize);
    for(i=0;i<numsSize;i++){
        arr2[i] = 1;
    }
    for(i=numsSize-2;i>=0;i--){
        for(j=numsSize-1;j>i;j--){
            if(nums[j] < nums[i]){
                arr2[i] = (arr2[i] < arr2[j] + 1) ? arr2[i] : arr2[j] + 1;
            }
        }
    }
    int max2 = 0;
    for(i=0;i<numsSize;i++){
        if(arr2[i] > max2){
            max2 = arr2[i];
        }
    }
    return numsSize - max - max2 + 1;

}

    