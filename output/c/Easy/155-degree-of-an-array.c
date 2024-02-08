/**https://leetcode.com/problems/degree-of-an-array/ */
//Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.
//Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.


int findShortestSubArray(int* nums, int numsSize){
    int i = 0;
    int j = 0;
    int temp = 0;
    int result = 0;
    int count = 0;
    for(i = 0; i < numsSize - 1; i++){
        for(j = 0; j < numsSize - i - 1; j++){
            if(nums[j] > nums[j + 1]){
                temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }
    for(i = 0; i < numsSize - 1; i++){
        if(nums[i] < nums[i + 1]){
            count++;
        }else{
            count = 0;
        }
        if(count > result){
            result = count;
        }
    }
    return result + 1;

}

    