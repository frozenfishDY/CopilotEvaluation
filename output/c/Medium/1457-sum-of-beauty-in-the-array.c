/**https://leetcode.com/problems/sum-of-beauty-in-the-array/ */
//You are given a 0-indexed integer array nums. For each index i (1 <= i <= nums.length - 2) the beauty of nums[i] equals:
//2, if nums[j] < nums[i] < nums[k], for all 0 <= j < i and for all i < k <= nums.length - 1.
//1, if nums[i - 1] < nums[i] < nums[i + 1], and the previous condition is not satisfied.
//0, if none of the previous conditions holds.
//Return the sum of beauty of all nums[i] where 1 <= i <= nums.length - 2.


int sumOfBeauties(int* nums, int numsSize){
    int i, j;
    int count = 0;
    int max = 0;
    int min = 100000;
    for(i = 1; i < numsSize - 1; i++){
        for(j = 0; j < i; j++){
            if(nums[j] > max){
                max = nums[j];
            }
        }
        for(j = i + 1; j < numsSize; j++){
            if(nums[j] < min){
                min = nums[j];
            }
        }
        if(nums[i] > max && nums[i] < min){
            count += 2;
        }
        else if(nums[i - 1] < nums[i] && nums[i] < nums[i + 1]){
            count++;
        }
        max = 0;
        min = 100000;
    }
    return count;

}

    