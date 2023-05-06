/**https://leetcode.com/problems/difference-between-element-sum-and-digit-sum-of-an-array/ */
//You are given a positive integer array nums.
//The element sum is the sum of all the elements in nums.
//The digit sum is the sum of all the digits (not necessarily distinct) that appear in nums.
//Return the absolute difference between the element sum and digit sum of nums.
//Note that the absolute difference between two integers x and y is defined as |x - y|.


int differenceOfSum(int* nums, int numsSize){
    int elementSum = 0;
    int digitSum = 0;
    int i = 0;
    int j = 0;
    int temp = 0;
    for(i = 0; i < numsSize; i++){
        elementSum += nums[i];
        temp = nums[i];
        while(temp > 0){
            digitSum += temp % 10;
            temp /= 10;
        }
    }
    return abs(elementSum - digitSum);

}

    