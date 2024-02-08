/**https://leetcode.com/problems/maximum-sum-circular-subarray/ */
//Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.
//A circular array means the end of the array connects to the beginning of the array. Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].
//A subarray may only include each element of the fixed buffer nums at most once. Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.


int maxSubarraySumCircular(int* nums, int numsSize){
    int max = nums[0];
    int min = nums[0];
    int sum = nums[0];
    int maxSum = nums[0];
    int minSum = nums[0];
    for(int i = 1; i < numsSize; i++){
        sum += nums[i];
        if(max + nums[i] > nums[i]){
            max += nums[i];
        }else{
            max = nums[i];
        }
        if(max > maxSum){
            maxSum = max;
        }
        if(min + nums[i] < nums[i]){
            min += nums[i];
        }else{
            min = nums[i];
        }
        if(min < minSum){
            minSum = min;
        }
    }
    if(maxSum > 0){
        return sum - minSum > maxSum ? sum - minSum : maxSum;
    }else{
        return maxSum;
    }

}

    