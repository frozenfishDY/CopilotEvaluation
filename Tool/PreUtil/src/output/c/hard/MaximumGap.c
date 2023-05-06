/**https://leetcode.com/problems/maximum-gap/ */
//Given an integer array nums, return the maximum difference between two successive elements in its sorted form. If the array contains less than two elements, return 0.
//You must write an algorithm that runs in linear time and uses linear extra space.


int maximumGap(int* nums, int numsSize){
    if(numsSize < 2) return 0;
    int max = nums[0];
    int min = nums[0];
    for(int i = 1; i < numsSize; i++){
        if(nums[i] > max) max = nums[i];
        if(nums[i] < min) min = nums[i];
    }
    int bucketSize = (max - min) / numsSize + 1;
    int bucketNum = (max - min) / bucketSize + 1;
    int* bucketMin = (int*)malloc(sizeof(int) * bucketNum);
    int* bucketMax = (int*)malloc(sizeof(int) * bucketNum);
    for(int i = 0; i < bucketNum; i++){
        bucketMin[i] = INT_MAX;
        bucketMax[i] = INT_MIN;
    }
    for(int i = 0; i < numsSize; i++){
        int index = (nums[i] - min) / bucketSize;
        if(nums[i] < bucketMin[index]) bucketMin[index] = nums[i];
        if(nums[i] > bucketMax[index]) bucketMax[index] = nums[i];
    }
    int maxGap = 0;
    int prev = bucketMax[0];
    for(int i = 1; i < bucketNum; i++){
        if(bucketMin[i] == INT_MAX && bucketMax[i] == INT_MIN) continue;
        if(bucketMin[i] - prev > maxGap) maxGap = bucketMin[i] - prev;
        prev = bucketMax[i];
    }
    return maxGap;
    


}

    