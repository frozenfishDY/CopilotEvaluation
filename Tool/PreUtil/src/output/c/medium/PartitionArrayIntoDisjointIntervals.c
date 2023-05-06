/**https://leetcode.com/problems/partition-array-into-disjoint-intervals/ */
//Given an integer array nums, partition it into two (contiguous) subarrays left and right so that:
//Every element in left is less than or equal to every element in right.
//left and right are non-empty.
//left has the smallest possible size.
//Return the length of left after such a partitioning.
//Test cases are generated such that partitioning exists.


int partitionDisjoint(int* nums, int numsSize){
    int* maxLeft = (int*)malloc(sizeof(int) * numsSize);
    int* minRight = (int*)malloc(sizeof(int) * numsSize);
    maxLeft[0] = nums[0];
    for(int i = 1; i < numsSize; i++){
        if(nums[i] > maxLeft[i - 1]){
            maxLeft[i] = nums[i];
        }else{
            maxLeft[i] = maxLeft[i - 1];
        }
    }
    minRight[numsSize - 1] = nums[numsSize - 1];
    for(int i = numsSize - 2; i >= 0; i--){
        if(nums[i] < minRight[i + 1]){
            minRight[i] = nums[i];
        }else{
            minRight[i] = minRight[i + 1];
        }
    }
    for(int i = 0; i < numsSize - 1; i++){
        if(maxLeft[i] <= minRight[i + 1]){
            return i + 1;
        }
    }
    return 0;

}

    