/**https://leetcode.com/problems/contains-duplicate/ */
//Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

bool containsDuplicate(int* nums, int numsSize){
    int map[100000] = {0};
    for(int i = 0; i < numsSize; i++){
        if(map[nums[i]] == 1){
            return true;
        }
        map[nums[i]] = 1;
    }
    return false;

}
    