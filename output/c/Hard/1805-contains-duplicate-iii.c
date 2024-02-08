/**https://leetcode.com/problems/contains-duplicate-iii/ */
//You are given an integer array nums and two integers indexDiff and valueDiff.
//Find a pair of indices (i, j) such that:
//i != j,
//abs(i - j) <= indexDiff.
//abs(nums[i] - nums[j]) <= valueDiff, and
//Return true if such pair exists or false otherwise.


bool containsNearbyAlmostDuplicate(int* nums, int numsSize, int indexDiff, int valueDiff){
    if(numsSize < 2) return false;
    int* index = (int*)malloc(sizeof(int) * numsSize);
    for(int i = 0; i < numsSize; i++) index[i] = i;
    qsort(index, numsSize, sizeof(int), cmp);
    for(int i = 0; i < numsSize; i++){
        for(int j = i + 1; j < numsSize; j++){
            if(index[j] - index[i] > indexDiff) break;
            if(abs(nums[index[i]] - nums[index[j]]) <= valueDiff) return true;
        }
    }
    return false;

}

    