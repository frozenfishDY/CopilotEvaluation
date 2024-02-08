/**https://leetcode.com/problems/lexicographical-numbers/ */
//Given an integer n, return all the numbers in the range [1, n] sorted in lexicographical order.
//You must write an algorithm that runs in O(n) time and uses O(1) extra space. 


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* lexicalOrder(int n, int* returnSize){
    int* result = (int*)malloc(sizeof(int) * n);
    int resultSize = 0;
    int current = 1;
    for(int i = 0; i < n; i++){
        result[resultSize++] = current;
        if(current * 10 <= n){
            current *= 10;
        }else{
            if(current >= n){
                current /= 10;
            }
            current++;
            while(current % 10 == 0){
                current /= 10;
            }
        }
    }
    *returnSize = resultSize;
    return result;

}

    