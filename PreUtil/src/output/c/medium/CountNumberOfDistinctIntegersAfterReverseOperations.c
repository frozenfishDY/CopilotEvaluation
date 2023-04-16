/**https://leetcode.com/problems/count-number-of-distinct-integers-after-reverse-operations/ */
//You are given an array nums consisting of positive integers.
//You have to take each integer in the array, reverse its digits, and add it to the end of the array. You should apply this operation to the original integers in nums.
//Return the number of distinct integers in the final array.


int countDistinctIntegers(int* nums, int numsSize){
    int i, j, k, count = 0, temp = 0, sum = 0;
    for(i = 0; i < numsSize; i++){
        sum = 0;
        for(j = i; j < numsSize; j++){
            temp = nums[j];
            while(temp != 0){
                sum = sum * 10 + temp % 10;
                temp = temp / 10;
            }
            nums[j] = sum;
            sum = 0;
        }
    }
    for(i = 0; i < numsSize; i++){
        for(j = i+1; j < numsSize; j++){
            if(nums[i] == nums[j]){
                count++;
                break;
            }
        }
    }
    return numsSize - count;

}

    