/**https://leetcode.com/problems/maximum-product-of-three-numbers/ */
//Given an integer array nums, find three numbers whose product is maximum and return the maximum product.


int maximumProduct(int* nums, int numsSize){
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
    if(nums[0] * nums[1] * nums[numsSize - 1] > nums[numsSize - 1] * nums[numsSize - 2] * nums[numsSize - 3]){
        return nums[0] * nums[1] * nums[numsSize - 1];
    }else{
        return nums[numsSize - 1] * nums[numsSize - 2] * nums[numsSize - 3];
    }

}

    