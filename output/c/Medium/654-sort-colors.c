/**https://leetcode.com/problems/sort-colors/ */
//Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
//We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
//You must solve this problem without using the library's sort function.


void sortColors(int* nums, int numsSize){
    int red = 0;
    int white = 0;
    int blue = 0;
    for(int i = 0; i < numsSize; i++){
        if(nums[i] == 0){
            red++;
        }
        else if(nums[i] == 1){
            white++;
        }
        else{
            blue++;
        }
    }
    for(int i = 0; i < numsSize; i++){
        if(red > 0){
            nums[i] = 0;
            red--;
        }
        else if(white > 0){
            nums[i] = 1;
            white--;
        }
        else{
            nums[i] = 2;
            blue--;
        }
    }

}

    