/**https://leetcode.com/problems/jump-game-vi/ */
//You are given a 0-indexed integer array nums and an integer k.
//You are initially standing at index 0. In one move, you can jump at most k steps forward without going outside the boundaries of the array. That is, you can jump from index i to any index in the range [i + 1, min(n - 1, i + k)] inclusive.
//You want to reach the last index of the array (index n - 1). Your score is the sum of all nums[j] for each index j you visited in the array.
//Return the maximum score you can get.


int maxResult(int* nums, int numsSize, int k){
    int* arr = malloc(numsSize * sizeof(int));
    arr[0] = nums[0];
    for(int i = 1; i < numsSize; i++){
        int max = arr[i - 1];
        for(int j = i - 2; j >= 0 && i - j <= k; j--){
            if(arr[j] > max){
                max = arr[j];
            }
        }
        arr[i] = max + nums[i];
    }
    return arr[numsSize - 1];

}

    