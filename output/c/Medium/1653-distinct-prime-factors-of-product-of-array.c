/**https://leetcode.com/problems/distinct-prime-factors-of-product-of-array/ */
//Given an array of positive integers nums, return the number of distinct prime factors in the product of the elements of nums.
//Note that:
//A number greater than 1 is called prime if it is divisible by only 1 and itself.
//An integer val1 is a factor of another integer val2 if val2 / val1 is an integer.


int distinctPrimeFactors(int* nums, int numsSize){
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

    