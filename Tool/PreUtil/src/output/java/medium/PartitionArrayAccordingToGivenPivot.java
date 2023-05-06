/**https://leetcode.com/problems/partition-array-according-to-given-pivot/ */
//You are given a 0-indexed integer array nums and an integer pivot. Rearrange nums such that the following conditions are satisfied:
//Every element less than pivot appears before every element greater than pivot.
//Every element equal to pivot appears in between the elements less than and greater than pivot.
//The relative order of the elements less than pivot and the elements greater than pivot is maintained.
//More formally, consider every pi, pj where pi is the new position of the ith element and pj is the new position of the jth element. For elements less than pivot, if i < j and nums[i] < pivot and nums[j] < pivot, then pi < pj. Similarly for elements greater than pivot, if i < j and nums[i] > pivot and nums[j] > pivot, then pi < pj.
//Return nums after the rearrangement.


class PartitionArrayAccordingToGivenPivot {
    public int[] pivotArray(int[] nums, int pivot) {
        int i = 0, j = 0, k = nums.length - 1;
        while(j <= k){
            if(nums[j] < pivot){
                swap(nums, i, j);
                i++;
                j++;
            }else if(nums[j] > pivot){
                swap(nums, j, k);
                k--;
            }else{
                j++;
            }
        }
        return nums;
        
        
    }
}
     
    