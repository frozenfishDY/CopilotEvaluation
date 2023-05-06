/**https://leetcode.com/problems/pancake-sorting/ */
//Given an array of integers arr, sort the array by performing a series of pancake flips.
//In one pancake flip we do the following steps:
//Choose an integer k where 1 <= k <= arr.length.
//Reverse the sub-array arr[0...k-1] (0-indexed).
//For example, if arr = [3,2,1,4] and we performed a pancake flip choosing k = 3, we reverse the sub-array [3,2,1], so arr = [1,2,3,4] after the pancake flip at k = 3.
//Return an array of the k-values corresponding to a sequence of pancake flips that sort arr. Any valid answer that sorts the array within 10 * arr.length flips will be judged as correct.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* pancakeSort(int* arr, int arrSize, int* returnSize){
    int* result = (int*)malloc(sizeof(int) * 1000);
    *returnSize = 0;
    int* temp = (int*)malloc(sizeof(int) * arrSize);
    for(int i = 0; i < arrSize; i++){
        temp[i] = arr[i];
    }
    int tempSize = arrSize;
    for(int i = 0; i < arrSize; i++){
        int max = 0;
        int maxIndex = 0;
        for(int j = 0; j < tempSize; j++){
            if(temp[j] > max){
                max = temp[j];
                maxIndex = j;
            }
        }
        if(maxIndex != tempSize - 1){
            result[*returnSize] = maxIndex + 1;
            (*returnSize)++;
            for(int j = 0; j < (maxIndex + 1) / 2; j++){
                int temp2 = temp[j];
                temp[j] = temp[maxIndex - j];
                temp[maxIndex - j] = temp2;
            }
            result[*returnSize] = tempSize;
            (*returnSize)++;
            for(int j = 0; j < tempSize / 2; j++){
                int temp2 = temp[j];
                temp[j] = temp[tempSize - j - 1];
                temp[tempSize - j - 1] = temp2;
            }
        }
        tempSize--;
    }
    free(temp);
    return result;

}

    