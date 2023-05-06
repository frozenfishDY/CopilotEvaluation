/**https://leetcode.com/problems/find-original-array-from-doubled-array/ */
//An integer array original is transformed into a doubled array changed by appending twice the value of every element in original, and then randomly shuffling the resulting array.
//Given an array changed, return original if changed is a doubled array. If changed is not a doubled array, return an empty array. The elements in original may be returned in any order.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findOriginalArray(int* changed, int changedSize, int* returnSize){
    int* arr = malloc(changedSize * sizeof(int));
    int i, j;
    int count = 0;
    for(i = 0; i < changedSize; i++){
        arr[i] = 0;
    }
    for(i = 0; i < changedSize; i++){
        for(j = i + 1; j < changedSize; j++){
            if(changed[i] == changed[j] * 2){
                arr[i] = 1;
                arr[j] = 1;
            }
        }
    }
    for(i = 0; i < changedSize; i++){
        if(arr[i] == 1){
            count++;
        }
    }
    int* arr1 = malloc(count * sizeof(int));
    int index = 0;
    for(i = 0; i < changedSize; i++){
        if(arr[i] == 1){
            arr1[index] = changed[i];
            index++;
        }
    }
    for(i = 0; i < count; i++){
        for(j = i + 1; j < count; j++){
            if(arr1[i] == arr1[j] * 2){
                arr1[j] = -1;
            }
        }
    }
    for(i = 0; i < count; i++){
        if(arr1[i] == -1){
            count--;
        }
    }
    int* arr2 = malloc(count * sizeof(int));
    index = 0;
    for(i = 0; i < count; i++){
        if(arr1[i] != -1){
            arr2[index] = arr1[i];
            index++;
        }
    }
    *returnSize = count;
    return arr2;

}

    