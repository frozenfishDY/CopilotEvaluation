/**https://leetcode.com/problems/minimum-moves-to-make-array-complementary/ */
//You are given an integer array nums of even length n and an integer limit. In one move, you can replace any integer from nums with another integer between 1 and limit, inclusive.
//The array nums is complementary if for all indices i (0-indexed), nums[i] + nums[n - 1 - i] equals the same number. For example, the array [1,2,3,4] is complementary because for all indices i, nums[i] + nums[n - 1 - i] = 5.
//Return the minimum number of moves required to make nums complementary.


int minMoves(int* nums, int numsSize, int limit){
    int* arr = malloc((2 * limit + 2) * sizeof(int));
    memset(arr, 0, (2 * limit + 2) * sizeof(int));
    for(int i = 0; i < numsSize / 2; i++){
        int a = nums[i];
        int b = nums[numsSize - 1 - i];
        arr[2] += 2;
        arr[fmin(a, b) + 1]--;
        arr[a + b]--;
        arr[a + b + 1]++;
        arr[fmax(a, b) + limit + 1]++;
    }
    int count = numsSize;
    int minCount = numsSize;
    for(int i = 2; i <= 2 * limit; i++){
        count += arr[i];
        minCount = fmin(minCount, count);
    }
    return minCount;

}

    