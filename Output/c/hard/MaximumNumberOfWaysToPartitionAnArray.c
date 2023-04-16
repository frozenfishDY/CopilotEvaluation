/**https://leetcode.com/problems/maximum-number-of-ways-to-partition-an-array/ */
//You are given a 0-indexed integer array nums of length n. The number of ways to partition nums is the number of pivot indices that satisfy both conditions:
//1 <= pivot < n
//nums[0] + nums[1] + ... + nums[pivot - 1] == nums[pivot] + nums[pivot + 1] + ... + nums[n - 1]
//You are also given an integer k. You can choose to change the value of one element of nums to k, or to leave the array unchanged.
//Return the maximum possible number of ways to partition nums to satisfy both conditions after changing at most one element.


int waysToPartition(int* nums, int numsSize, int k){
    int i,j,k;
    int* arr = (int*)malloc(sizeof(int)*numsSize);
    for(i=0;i<numsSize;i++){
        arr[i] = 0;
    }
    arr[0] = 1;
    for(i=1;i<numsSize;i++){
        arr[i] = arr[i-1] + 1;
        if(i%2==0){
            arr[i] = (arr[i] < arr[i/2] + 1) ? arr[i] : arr[i/2] + 1;
        }
        if(i%3==0){
            arr[i] = (arr[i] < arr[i/3] + 1) ? arr[i] : arr[i/3] + 1;
        }
    }
    return arr[numsSize-1];

}

    