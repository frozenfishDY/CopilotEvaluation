/**https://leetcode.com/problems/maximum-erasure-value/ */
//You are given an array of positive integers nums and want to erase a subarray containing unique elements. The score you get by erasing the subarray is equal to the sum of its elements.
//Return the maximum score you can get by erasing exactly one subarray.
//An array b is called to be a subarray of a if it forms a contiguous subsequence of a, that is, if it is equal to a[l],a[l+1],...,a[r] for some (l,r).


int maximumUniqueSubarray(int* nums, int numsSize){
    int* arr = malloc(numsSize * sizeof(int));
    int sum = 0;
    for(int i = 0; i < numsSize; i++){
        sum += nums[i];
    }
    int leftSum = 0;
    for(int i = 0; i < numsSize; i++){
        arr[i] = (nums[i] * i - leftSum) + (sum - leftSum - nums[i] * (numsSize - i - 1));
        leftSum += nums[i];
    }
    int max = 0;
    for(int i = 0; i < numsSize; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;

}

    