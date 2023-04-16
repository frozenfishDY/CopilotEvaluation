/**https://leetcode.com/problems/count-increasing-quadruplets/ */
//Given a 0-indexed integer array nums of size n containing all numbers from 1 to n, return the number of increasing quadruplets.
//A quadruplet (i, j, k, l) is increasing if:
//0 <= i < j < k < l < n, and
//nums[i] < nums[k] < nums[j] < nums[l].


long long countQuadruplets(int* nums, int numsSize){
    int i, j, k, l;
    long long c = 0;
    for (i = 0; i < numsSize - 3; i++) {
        for (j = i + 1; j < numsSize - 2; j++) {
            for (k = j + 1; k < numsSize - 1; k++) {
                for (l = k + 1; l < numsSize; l++) {
                    if (nums[i] < nums[k] && nums[k] < nums[j] && nums[j] < nums[l]) {
                        c++;
                    }
                }
            }
        }
    }
    return c;

}

    