/**https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/ */
//Given an array nums sorted in non-decreasing order, return the maximum between the number of positive integers and the number of negative integers.
//In other words, if the number of positive integers in nums is pos and the number of negative integers is neg, then return the maximum of pos and neg.
//Note that 0 is neither positive nor negative.


int maximumCount(int* nums, int numsSize){
    int pos = 0;
    int neg = 0;
    int i = 0;
    while(i < numsSize){
        if(nums[i] > 0){
            pos++;
        }else if(nums[i] < 0){
            neg++;
        }
        i++;
    }
    if(pos > neg){
        return pos;
    }else{
        return neg;
    }

}

    