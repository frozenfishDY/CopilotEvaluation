/**https://leetcode.com/problems/patching-array/ */
//Given a sorted integer array nums and an integer n, add/patch elements to the array such that any number in the range [1, n] inclusive can be formed by the sum of some elements in the array.
//Return the minimum number of patches required.


int minPatches(int* nums, int numsSize, int n){
    int count = 0;
    long long sum = 0;
    int i = 0;
    while(sum < n){
        if(i < numsSize && nums[i] <= sum + 1){
            sum += nums[i++];
        }else{
            sum += sum + 1;
            count++;
        }
    }
    return count;

}

    