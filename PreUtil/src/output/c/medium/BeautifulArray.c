/**https://leetcode.com/problems/beautiful-array/ */
//An array nums of length n is beautiful if:
//nums is a permutation of the integers in the range [1, n].
//For every 0 <= i < j < n, there is no index k with i < k < j where 2 * nums[k] == nums[i] + nums[j].
//Given the integer n, return any beautiful array nums of length n. There will be at least one valid answer for the given n.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* beautifulArray(int n, int* returnSize){
    int* result = (int*)malloc(sizeof(int) * n);
    *returnSize = n;
    result[0] = 1;
    int length = 1;
    while(length < n){
        int* temp = (int*)malloc(sizeof(int) * n);
        int index = 0;
        for(int i = 0; i < length; i++){
            if(result[i] * 2 - 1 <= n){
                temp[index] = result[i] * 2 - 1;
                index++;
            }
        }
        for(int i = 0; i < length; i++){
            if(result[i] * 2 <= n){
                temp[index] = result[i] * 2;
                index++;
            }
        }
        free(result);
        result = temp;
        length = index;
    }
    return result;

}

    