/**https://leetcode.com/problems/sort-colors/ */
//Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
//We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
//You must solve this problem without using the library's sort function.


class SortColors {
    public void sortColors(int[] nums) {
        int n = nums.length;
        int p0 = 0;
        int p2 = n - 1;
        int curr = 0;
        while(curr <= p2){
            if(nums[curr] == 0){
                swap(nums, curr, p0);
                curr++;
                p0++;
            }else if(nums[curr] == 2){
                swap(nums, curr, p2);
                p2--;
            }else{
                curr++;
            }
        }
        
        
    }
}

    