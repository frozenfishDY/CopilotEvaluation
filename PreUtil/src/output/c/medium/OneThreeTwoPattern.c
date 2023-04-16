/**https://leetcode.com/problems/132-pattern/ */
//Given an array of n integers nums, a 132 pattern is a subsequence of three integers nums[i], nums[j] and nums[k] such that i < j < k and nums[i] < nums[k] < nums[j].
//Return true if there is a 132 pattern in nums, otherwise, return false.


bool find132pattern(int* nums, int numsSize){
    int* result = (int*)malloc(sizeof(int) * numsSize);
    int resultSize = 0;
    for(int i = 0; i < numsSize; i++){
        int num = nums[i];
        for(int j = 2; j <= num; j++){
            if(num % j == 0){
                result[resultSize++] = j;
                while(num % j == 0){
                    num /= j;
                }
            }
        }
    }
    int count = 0;
    for(int i = 0; i < resultSize; i++){
        int j = 0;
        for(; j < i; j++){
            if(result[j] == result[i]){
                break;
            }
        }
        if(j == i){
            count++;
        }
    }
    return count;

}

    