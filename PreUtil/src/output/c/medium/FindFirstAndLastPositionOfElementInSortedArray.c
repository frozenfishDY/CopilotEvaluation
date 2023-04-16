/**https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/ */
//Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
//If target is not found in the array, return [-1, -1].
//You must write an algorithm with O(log n) runtime complexity.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int low = 0;
    int high = numsSize - 1;
    int mid = 0;
    int* result = (int*)malloc(sizeof(int) * 2);
    result[0] = -1;
    result[1] = -1;
    *returnSize = 2;
    while(low <= high){
        mid = (low + high) / 2;
        if(nums[mid] == target){
            int i = mid;
            int j = mid;
            while(i >= 0 && nums[i] == target){
                i--;
            }
            while(j < numsSize && nums[j] == target){
                j++;
            }
            result[0] = i + 1;
            result[1] = j - 1;
            return result;
        }
        if(nums[low] <= nums[mid]){
            if(target >= nums[low] && target < nums[mid]){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        else{
            if(target > nums[mid] && target <= nums[high]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
    }
    return result;

}

    