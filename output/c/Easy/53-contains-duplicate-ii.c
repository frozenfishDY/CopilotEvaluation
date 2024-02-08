/**https://leetcode.com/problems/contains-duplicate-ii/ */
//Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

bool containsNearbyDuplicate(int* nums, int numsSize, int k){
    int map[100000] = {0};
    for(int i = 0; i < numsSize; i++){
        if(map[nums[i]] != 0 && i + 1 - map[nums[i]] <= k){
            return true;
        }
        map[nums[i]] = i + 1;
    }
    return false;

}
    