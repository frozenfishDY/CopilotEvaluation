/**https://leetcode.com/problems/3sum/ */
//Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
//Notice that the solution set must not contain duplicate triplets.


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int i = 0;
    int j = 0;
    int k = 0;
    int count = 0;
    int** result = NULL;
    *returnSize = 0;
    *returnColumnSizes = (int*)malloc(sizeof(int) * numsSize);
    for(i = 0; i < numsSize; i++){
        for(j = i + 1; j < numsSize; j++){
            for(k = j + 1; k < numsSize; k++){
                if(nums[i] + nums[j] + nums[k] == 0){
                    count++;
                    *returnSize = count;
                    result = (int**)realloc(result, sizeof(int*) * count);
                    result[count - 1] = (int*)malloc(sizeof(int) * 3);
                    result[count - 1][0] = nums[i];
                    result[count - 1][1] = nums[j];
                    result[count - 1][2] = nums[k];
                    (*returnColumnSizes)[count - 1] = 3;
                }
            }
        }
    }
    return result;

}

    