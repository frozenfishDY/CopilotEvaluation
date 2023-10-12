/**https://leetcode.com/problems/count-special-quadruplets/ */
//Given a 0-indexed integer array nums, return the number of distinct quadruplets (a, b, c, d) such that:
//	nums[a] + nums[b] + nums[c] == nums[d], and
//	a < b < c < d
// 
//Example 1:
//Input: nums = [1,2,3,6]
//Output: 1
//Explanation: The only quadruplet that satisfies the requirement is (0, 1, 2, 3) because 1 + 2 + 3 == 6.
//Example 2:
//Input: nums = [3,3,6,4,5]
//Output: 0
//Explanation: There are no such quadruplets in [3,3,6,4,5].
//Example 3:
//Input: nums = [1,1,1,3,5]
//Output: 4
//Explanation: The 4 quadruplets that satisfy the requirement are:
//- (0, 1, 2, 3): 1 + 1 + 1 == 3
//- (0, 1, 3, 4): 1 + 1 + 3 == 5
//- (0, 2, 3, 4): 1 + 1 + 3 == 5
//- (1, 2, 3, 4): 1 + 1 + 3 == 5
// 
//Constraints:
//	4 <= nums.length <= 50
//	1 <= nums[i] <= 100
int countQuadruplets(int* nums, int numsSize){
int i = 0, j = 0, k = 0, l = 0, max = 0, cnt = 0;
    for(i = 0; i < numsSize; i++){
        for(j = i + 1; j < numsSize; j++){
            for(k = j + 1; k < numsSize; k++){
                for(l = k + 1; l < numsSize; l++){
                    if(nums[i] + nums[j] + nums[k] == nums[l]){
                        cnt++;
                    }
                }
            }
        }
    }
    return cnt;
}