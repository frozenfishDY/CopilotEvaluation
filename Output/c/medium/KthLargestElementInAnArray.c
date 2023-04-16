/**https://leetcode.com/problems/kth-largest-element-in-an-array/ */
//Given an integer array nums and an integer k, return the kth largest element in the array.
//Note that it is the kth largest element in the sorted order, not the kth distinct element.
//You must solve it in O(n) time complexity.


int findKthLargest(int* nums, int numsSize, int k){
    int left = 0;
    int right = numsSize - 1;
    while(left <= right){
        int pivot = nums[left];
        int i = left;
        int j = right;
        while(i < j){
            while(i < j && nums[j] <= pivot){
                j--;
            }
            nums[i] = nums[j];
            while(i < j && nums[i] >= pivot){
                i++;
            }
            nums[j] = nums[i];
        }
        nums[i] = pivot;
        if(i == k - 1){
            return nums[i];
        }
        else if(i < k - 1){
            left = i + 1;
        }
        else{
            right = i - 1;
        }
    }
    return -1;

}

    