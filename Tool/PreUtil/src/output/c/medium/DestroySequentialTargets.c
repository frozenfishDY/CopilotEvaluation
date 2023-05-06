/**https://leetcode.com/problems/destroy-sequential-targets/ */
//You are given a 0-indexed array nums consisting of positive integers, representing targets on a number line. You are also given an integer space.
//You have a machine which can destroy targets. Seeding the machine with some nums[i] allows it to destroy all targets with values that can be represented as nums[i] + c * space, where c is any non-negative integer. You want to destroy the maximum number of targets in nums.
//Return the minimum value of nums[i] you can seed the machine with to destroy the maximum number of targets.


int destroyTargets(int* nums, int numsSize, int space){
    int i, j;
    int count = 0;
    int max = 0;
    int arr[100000] = {0};
    for(i = 0; i < numsSize; i++){
        for(j = 0; j < 100000; j++){
            if(nums[i] + j * space < 100000){
                arr[nums[i] + j * space] = 1;
            }
        }
    }
    for(i = 0; i < 100000; i++){
        if(arr[i] == 1){
            count++;
        }
    }
    return count;

}

    