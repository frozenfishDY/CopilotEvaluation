/**https://leetcode.com/problems/combination-sum-iv/ */
//Given an array of distinct integers nums and a target integer target, return the number of possible combinations that add up to target.
//The test cases are generated so that the answer can fit in a 32-bit integer.


int combinationSum4(int* nums, int numsSize, int target){
    int* result = (int*)malloc(sizeof(int) * (target + 1));
    result[0] = 1;
    for(int i = 1; i <= target; i++){
        result[i] = 0;
        for(int j = 0; j < numsSize; j++){
            if(i - nums[j] >= 0){
                result[i] += result[i - nums[j]];
            }
        }
    }
    return result[target];

}

    