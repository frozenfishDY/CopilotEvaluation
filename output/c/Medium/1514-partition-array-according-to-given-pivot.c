/**https://leetcode.com/problems/partition-array-according-to-given-pivot/ */
//You are given a 0-indexed integer array nums and an integer pivot. Rearrange nums such that the following conditions are satisfied:
//Every element less than pivot appears before every element greater than pivot.
//Every element equal to pivot appears in between the elements less than and greater than pivot.
//The relative order of the elements less than pivot and the elements greater than pivot is maintained.
//More formally, consider every pi, pj where pi is the new position of the ith element and pj is the new position of the jth element. For elements less than pivot, if i < j and nums[i] < pivot and nums[j] < pivot, then pi < pj. Similarly for elements greater than pivot, if i < j and nums[i] > pivot and nums[j] > pivot, then pi < pj.
//Return nums after the rearrangement.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* pivotArray(int* nums, int numsSize, int pivot, int* returnSize){
    int* arr = malloc(numsSize * sizeof(int));
    int i, j, k, l;
    for(i = 0; i < numsSize; i++){
        arr[i] = nums[i];
    }
    for(i = 0; i < numsSize; i++){
        for(j = i + 1; j < numsSize; j++){
            if(arr[i] > arr[j]){
                k = arr[i];
                arr[i] = arr[j];
                arr[j] = k;
            }
        }
    }
    for(i = 0; i < numsSize; i++){
        if(arr[i] == pivot){
            break;
        }
    }
    for(j = i + 1; j < numsSize; j++){
        if(arr[j] > pivot){
            break;
        }
    }
    for(k = j + 1; k < numsSize; k++){
        if(arr[k] == pivot){
            break;
        }
    }
    for(l = k + 1; l < numsSize; l++){
        if(arr[l] < pivot){
            break;
        }
    }
    *returnSize = numsSize;
    return arr;

}

    