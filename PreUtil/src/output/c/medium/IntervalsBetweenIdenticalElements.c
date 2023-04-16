/**https://leetcode.com/problems/intervals-between-identical-elements/ */
//You are given a 0-indexed array of n integers arr.
//The interval between two elements in arr is defined as the absolute difference between their indices. More formally, the interval between arr[i] and arr[j] is |i - j|.
//Return an array intervals of length n where intervals[i] is the sum of intervals between arr[i] and each element in arr with the same value as arr[i].
//Note: |x| is the absolute value of x.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
long long* getDistances(int* arr, int arrSize, int* returnSize){
    long long* arr1 = malloc(arrSize * sizeof(long long));
    int i, j;
    for(i = 0; i < arrSize; i++){
        arr1[i] = 0;
    }
    for(i = 0; i < arrSize; i++){
        for(j = i + 1; j < arrSize; j++){
            if(arr[i] == arr[j]){
                arr1[i] += j - i;
                arr1[j] += j - i;
            }
        }
    }
    *returnSize = arrSize;
    return arr1;

}

    