/**https://leetcode.com/problems/minimum-operations-to-halve-array-sum/ */
//You are given an array nums of positive integers. In one operation, you can choose any number from nums and reduce it to exactly half the number. (Note that you may choose this reduced number in future operations.)
//Return the minimum number of operations to reduce the sum of nums by at least half.


int halveArray(int* nums, int numsSize){
    int i, j;
    int sum = 0;
    int count = 0;
    for(i = 0; i < numsSize; i++){
        sum += nums[i];
    }
    for(i = 0; i < numsSize; i++){
        sum -= nums[i];
        count++;
        if(sum < numsSize){
            break;
        }
    }
    return count;


}

    