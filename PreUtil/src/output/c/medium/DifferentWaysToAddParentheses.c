/**https://leetcode.com/problems/different-ways-to-add-parentheses/ */
//Given a string expression of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. You may return the answer in any order.
//The test cases are generated such that the output values fit in a 32-bit integer and the number of different results does not exceed 104.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* diffWaysToCompute(char * expression, int* returnSize){
    int* result = (int*)malloc(sizeof(int) * 10000);
    int resultSize = 0;
    int expressionSize = strlen(expression);
    for(int i = 0; i < expressionSize; i++){
        if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*'){
            int* left = diffWaysToCompute(strndup(expression, i), returnSize);
            int* right = diffWaysToCompute(strndup(expression + i + 1, expressionSize - i - 1), returnSize);
            for(int j = 0; j < *returnSize; j++){
                for(int k = 0; k < *returnSize; k++){
                    if(expression[i] == '+'){
                        result[resultSize++] = left[j] + right[k];
                    }
                    else if(expression[i] == '-'){
                        result[resultSize++] = left[j] - right[k];
                    }
                    else if(expression[i] == '*'){
                        result[resultSize++] = left[j] * right[k];
                    }
                }
            }
        }
    }
    if(resultSize == 0){
        result[resultSize++] = atoi(expression);
    }
    *returnSize = resultSize;
    return result;

}

    