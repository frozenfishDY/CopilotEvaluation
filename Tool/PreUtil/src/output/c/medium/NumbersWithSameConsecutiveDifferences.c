/**https://leetcode.com/problems/numbers-with-same-consecutive-differences/ */
//Given two integers n and k, return an array of all the integers of length n where the difference between every two consecutive digits is k. You may return the answer in any order.
//Note that the integers should not have leading zeros. Integers as 02 and 043 are not allowed.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* numsSameConsecDiff(int n, int k, int* returnSize){
    int* result = (int*)malloc(sizeof(int) * 1000);
    *returnSize = 0;
    if(n == 1){
        for(int i = 0; i < 10; i++){
            result[*returnSize] = i;
            (*returnSize)++;
        }
        return result;
    }
    int* temp = (int*)malloc(sizeof(int) * 1000);
    int tempSize = 0;
    for(int i = 1; i < 10; i++){
        temp[tempSize] = i;
        tempSize++;
    }
    for(int i = 1; i < n; i++){
        int* temp2 = (int*)malloc(sizeof(int) * 1000);
        int temp2Size = 0;
        for(int j = 0; j < tempSize; j++){
            int last = temp[j] % 10;
            if(last + k < 10){
                temp2[temp2Size] = temp[j] * 10 + last + k;
                temp2Size++;
            }
            if(last - k >= 0 && k != 0){
                temp2[temp2Size] = temp[j] * 10 + last - k;
                temp2Size++;
            }
        }
        free(temp);
        temp = temp2;
        tempSize = temp2Size;
    }
    for(int i = 0; i < tempSize; i++){
        result[*returnSize] = temp[i];
        (*returnSize)++;
    }
    free(temp);
    return result;

}

    