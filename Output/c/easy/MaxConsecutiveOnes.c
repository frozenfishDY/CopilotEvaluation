/**https://leetcode.com/problems/max-consecutive-ones/ */
//Given a binary array nums, return the maximum number of consecutive 1's in the array.


int findMaxConsecutiveOnes(int* nums, int numsSize){
    int max = 0;
    int count = 0;
    int i = 0;
    while(i < numsSize){
        if(nums[i] == 1){
            count++;
        }else{
            if(count > max){
                max = count;
            }
            count = 0;
        }
        i++;
    }
    if(count > max){
        max = count;
    }
    return max;

}

    