/**https://leetcode.com/problems/constrained-subsequence-sum/ */
//Given an integer array nums and an integer k, return the maximum sum of a non-empty subsequence of that array such that for every two consecutive integers in the subsequence, nums[i] and nums[j], where i < j, the condition j - i <= k is satisfied.
//A subsequence of an array is obtained by deleting some number of elements (can be zero) from the array, leaving the remaining elements in their original order.


int constrainedSubsetSum(int* nums, int numsSize, int k){
    int i,j,k;
    int* arr = (int*)malloc(sizeof(int)*numsSize);
    for(i=0;i<numsSize;i++){
        arr[i] = nums[i];
    }
    for(i=1;i<numsSize;i++){
        int max = 0;
        for(j=i-1;j>=0 && i-j<=k;j--){
            if(arr[j]>max){
                max = arr[j];
            }
        }
        arr[i] = arr[i] + max;
    }
    int max = 0;
    for(i=0;i<numsSize;i++){
        if(arr[i]>max){
            max = arr[i];
        }
    }
    return max;

}

    