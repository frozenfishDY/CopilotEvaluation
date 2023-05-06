/**https://leetcode.com/problems/powerful-integers/ */
//Given three integers x, y, and bound, return a list of all the powerful integers that have a value less than or equal to bound.
//An integer is powerful if it can be represented as xi + yj for some integers i >= 0 and j >= 0.
//You may return the answer in any order. In your answer, each value should occur at most once.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* powerfulIntegers(int x, int y, int bound, int* returnSize){
    int* result = (int*)malloc(sizeof(int) * 1000);
    *returnSize = 0;
    int* temp = (int*)malloc(sizeof(int) * 1000);
    int tempSize = 0;
    int i = 0;
    int j = 0;
    int tempNum = 1;
    while(tempNum < bound){
        temp[tempSize] = tempNum;
        tempSize++;
        if(x == 1){
            break;
        }
        tempNum *= x;
        i++;
    }
    tempNum = 1;
    while(tempNum < bound){
        for(int k = 0; k < tempSize; k++){
            if(temp[k] + tempNum <= bound){
                result[*returnSize] = temp[k] + tempNum;
                (*returnSize)++;
            }
        }
        if(y == 1){
            break;
        }
        tempNum *= y;
        j++;
    }
    qsort(result, *returnSize, sizeof(int), cmp);
    int* result2 = (int*)malloc(sizeof(int) * 1000);
    int result2Size = 0;
    for(int i = 0; i < *returnSize; i++){
        if(i == 0 || result[i] != result[i - 1]){
            result2[result2Size] = result[i];
            result2Size++;
        }
    }
    *returnSize = result2Size;
    free(result);
    free(temp);
    return result2;


}

    