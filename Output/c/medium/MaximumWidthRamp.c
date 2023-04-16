/**https://leetcode.com/problems/maximum-width-ramp/ */
//A ramp in an integer array nums is a pair (i, j) for which i < j and nums[i] <= nums[j]. The width of such a ramp is j - i.
//Given an integer array nums, return the maximum width of a ramp in nums. If there is no ramp in nums, return 0.


int maxWidthRamp(int* nums, int numsSize){
    int* stack = (int*)malloc(sizeof(int) * numsSize);
    int top = -1;
    for(int i = 0; i < numsSize; i++){
        if(top == -1 || nums[stack[top]] > nums[i]){
            stack[++top] = i;
        }
    }
    int result = 0;
    for(int i = numsSize - 1; i >= 0; i--){
        while(top != -1 && nums[stack[top]] <= nums[i]){
            result = fmax(result, i - stack[top--]);
        }
    }
    return result;

}

    