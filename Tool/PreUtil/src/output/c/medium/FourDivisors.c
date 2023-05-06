/**https://leetcode.com/problems/four-divisors/ */
//Given an integer array nums, return the sum of divisors of the integers in that array that have exactly four divisors. If there is no such integer in the array, return 0.


int sumFourDivisors(int* nums, int numsSize){
    int i, j, k, sum = 0, count = 0;
    for(i = 0; i < numsSize; i++){
        count = 0;
        for(j = 1; j <= nums[i]; j++){
            if(nums[i] % j == 0){
                count++;
                sum += j;
            }
        }
        if(count != 4){
            sum = 0;
        }
    }
    return sum;

}

    