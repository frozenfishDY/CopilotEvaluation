/**https://leetcode.com/problems/shuffle-the-array/ */
//Given the array nums consisting of 2n elements in the form [x1,x2,...,xn,y1,y2,...,yn]._x000D_
//_x000D_
//Return the array in the form [x1,y1,x2,y2,...,xn,yn]._x000D_
//_x000D_
// _x000D_
//Example 1:_x000D_
//_x000D_
//_x000D_
//Input: nums = [2,5,1,3,4,7], n = 3_x000D_
//Output: [2,3,5,4,1,7] _x000D_
//Explanation: Since x1=2, x2=5, x3=1, y1=3, y2=4, y3=7 then the answer is [2,3,5,4,1,7]._x000D_
//_x000D_
//_x000D_
//Example 2:_x000D_
//_x000D_
//_x000D_
//Input: nums = [1,2,3,4,4,3,2,1], n = 4_x000D_
//Output: [1,4,2,3,3,2,4,1]_x000D_
//_x000D_
//_x000D_
//Example 3:_x000D_
//_x000D_
//_x000D_
//Input: nums = [1,1,2,2], n = 2_x000D_
//Output: [1,2,1,2]_x000D_
//_x000D_
//_x000D_
// _x000D_
//Constraints:_x000D_
//_x000D_
//_x000D_
//	1 <= n <= 500_x000D_
//	nums.length == 2n_x000D_
//	1 <= nums[i] <= 10^3_x000D_
class Solution {
    public int[] shuffle(int[] nums, int n) {
        int[] res = new int[nums.length];
        int j = 0;
        for(int i = 0; i < nums.length; i++){
            if(i % 2 == 0){
                res[i] = nums[j];
            }else{
                res[i] = nums[n + j];
                j++;
            }
        }
        return res;
    }
}