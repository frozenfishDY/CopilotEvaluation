/**https://leetcode.com/problems/sort-colors/ */
//Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
//We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
//You must solve this problem without using the library's sort function.


/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var sortColors = function(nums) {
    let n = nums.length;
    let p0 = 0;
    let p2 = n - 1;
    let i = 0;
    while(i <= p2){
        if(nums[i] == 0){
            swap(nums, i, p0);
            p0++;
            i++;
        }else if(nums[i] == 2){
            swap(nums, i, p2);
            p2--;
        }else{
            i++;
        }
    }
    
    
};

    