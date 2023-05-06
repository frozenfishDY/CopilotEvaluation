/**https://leetcode.com/problems/3sum-closest/ */
//Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.
//Return the sum of the three integers.
//You may assume that each input would have exactly one solution.


int threeSumClosest(int* nums, int numsSize, int target){
    int i = 0;
    int j = 0;
    int k = 0;
    int sum = 0;
    int min = 0;
    int result = 0;
    int flag = 0;
    for(i = 0; i < numsSize; i++){
        for(j = i + 1; j < numsSize; j++){
            for(k = j + 1; k < numsSize; k++){
                sum = nums[i] + nums[j] + nums[k];
                if(flag == 0){
                    min = abs(sum - target);
                    result = sum;
                    flag = 1;
                }
                if(abs(sum - target) < min){
                    min = abs(sum - target);
                    result = sum;
                }
            }
        }
    }
    return result;

}

    