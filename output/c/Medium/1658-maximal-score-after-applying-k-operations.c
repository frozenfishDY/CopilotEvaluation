/**https://leetcode.com/problems/maximal-score-after-applying-k-operations/ */
//You are given a 0-indexed integer array nums and an integer k. You have a starting score of 0.
//In one operation:
//choose an index i such that 0 <= i < nums.length,
//increase your score by nums[i], and
//replace nums[i] with ceil(nums[i] / 3).
//Return the maximum possible score you can attain after applying exactly k operations.
//The ceiling function ceil(val) is the least integer greater than or equal to val.


long long maxKelements(int* nums, int numsSize, int k){
    long long result = 0;
    for(int i = 0; i < k; i++){
        result += nums[i];
    }
    long long sum = result;
    for(int i = k; i < numsSize; i++){
        sum += nums[i];
        sum -= nums[i - k];
        if(sum > result){
            result = sum;
        }
    }
    return result;

}

    