/**https://leetcode.com/problems/closest-subsequence-sum/ */
//You are given an integer array nums and an integer goal.
//You want to choose a subsequence of nums such that the sum of its elements is the closest possible to goal. That is, if the sum of the subsequence's elements is sum, then you want to minimize the absolute difference abs(sum - goal).
//Return the minimum possible value of abs(sum - goal).
//Note that a subsequence of an array is an array formed by removing some elements (possibly all or none) of the original array.


int minAbsDifference(int* nums, int numsSize, int goal){
    int i,j,k;
    int* arr = (int*)malloc(sizeof(int)*numsSize);
    for(i=0;i<numsSize;i++){
        arr[i] = 0;
    }
    int count = 0;
    for(i=0;i<numsSize;i++){
        if(nums[i] == 1){
            arr[count] = i;
            count++;
        }
    }
    int* arr2 = (int*)malloc(sizeof(int)*numsSize);
    for(i=0;i<numsSize;i++){
        arr2[i] = 0;
    }
    for(i=0;i<numsSize;i++){
        for(j=0;j<numsSize;j++){
            arr2[i] += abs(arr[i+j] - arr[i+numsSize/2]);
        }
    }
    int min = arr2[0];
    for(i=0;i<numsSize;i++){
        if(arr2[i] < min){
            min = arr2[i];
        }
    }
    return min;

}

    