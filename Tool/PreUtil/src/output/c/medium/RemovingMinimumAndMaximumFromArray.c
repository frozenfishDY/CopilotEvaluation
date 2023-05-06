/**https://leetcode.com/problems/removing-minimum-and-maximum-from-array/ */
//You are given a 0-indexed array of distinct integers nums.
//There is an element in nums that has the lowest value and an element that has the highest value. We call them the minimum and maximum respectively. Your goal is to remove both these elements from the array.
//A deletion is defined as either removing an element from the front of the array or removing an element from the back of the array.
//Return the minimum number of deletions it would take to remove both the minimum and maximum element from the array.


int minimumDeletions(int* nums, int numsSize){
    int i, j;
    int min = 100000;
    int max = 0;
    int count = 0;
    for(i = 0; i < numsSize; i++){
        if(nums[i] < min){
            min = nums[i];
        }
        if(nums[i] > max){
            max = nums[i];
        }
    }
    for(i = 0; i < numsSize; i++){
        if(nums[i] == min){
            count++;
        }
        else{
            break;
        }
    }
    for(i = numsSize - 1; i >= 0; i--){
        if(nums[i] == max){
            count++;
        }
        else{
            break;
        }
    }
    return numsSize - count;

}

    