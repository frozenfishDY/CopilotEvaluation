/**https://leetcode.com/problems/third-maximum-number/ */
//Given an integer array nums, return the third distinct maximum number in this array. If the third maximum does not exist, return the maximum number.


int thirdMax(int* nums, int numsSize){
    int max1 = INT_MIN;
    int max2 = INT_MIN;
    int max3 = INT_MIN;
    int i = 0;
    int flag = 0;
    while(i < numsSize){
        if(nums[i] > max1){
            max3 = max2;
            max2 = max1;
            max1 = nums[i];
        }else if(nums[i] > max2 && nums[i] < max1){
            max3 = max2;
            max2 = nums[i];
        }else if(nums[i] > max3 && nums[i] < max2){
            max3 = nums[i];
        }
        i++;
    }
    if(max3 == INT_MIN){
        return max1;
    }
    return max3;

}

    