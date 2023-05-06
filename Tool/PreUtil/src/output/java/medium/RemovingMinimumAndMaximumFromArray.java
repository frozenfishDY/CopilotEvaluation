/**https://leetcode.com/problems/removing-minimum-and-maximum-from-array/ */
//You are given a 0-indexed array of distinct integers nums.
//There is an element in nums that has the lowest value and an element that has the highest value. We call them the minimum and maximum respectively. Your goal is to remove both these elements from the array.
//A deletion is defined as either removing an element from the front of the array or removing an element from the back of the array.
//Return the minimum number of deletions it would take to remove both the minimum and maximum element from the array.


class RemovingMinimumAndMaximumFromArray {
    public int minimumDeletions(int[] nums) {
        int min = Integer.MAX_VALUE;
        int max = Integer.MIN_VALUE;
        for(int i = 0; i < nums.length; i++){
            min = Math.min(min, nums[i]);
            max = Math.max(max, nums[i]);
        }
        int minIndex = 0;
        int maxIndex = 0;
        for(int i = 0; i < nums.length; i++){
            if(nums[i] == min){
                minIndex = i;
            }
            if(nums[i] == max){
                maxIndex = i;
            }
        }
        return Math.min(minIndex, nums.length - 1 - maxIndex);
        
    }
}
     
    